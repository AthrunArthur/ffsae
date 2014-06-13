#include "sae/sae.h"
#include "dsource/read.h"
#include <time.h>
#include <memory>
#include "nn/opt.h"
//ff parallel
#include "ff.h"

#define PARAGRANULARITY 7

using namespace ff;

int main(int argc, char *argv[])
{
    int elapsedTime = count_elapse_second([]{
        bool isPara = false;
        srand(time(NULL));
//     int nThread = 1;
//     if(isPara)
//       nThread = tbb::task_scheduler_init::automatic;
//     std::cout << "nThread = " << nThread << std::endl;
        TData d = read_data();
        *d.train_x = (*d.train_x) / 255;
        *d.test_x = (*d.test_x) / 255;

        //add for quick test
//    *d.train_x = submatrix(*d.train_x,0UL,0UL,opts.batchsize * 3,d.train_x->columns());
//    *d.train_y = submatrix(*d.train_y,0UL,0UL,opts.batchsize * 3,d.train_y->columns());
//    *d.test_x = submatrix(*d.test_x,0UL,0UL,opts.batchsize * 3,d.test_x->columns());
//    *d.test_y = submatrix(*d.test_y,0UL,0UL,opts.batchsize * 3,d.test_y->columns());

        //train a 100 hidden unit SDAE and use it to initialize a FFNN
        //Setup and train a stacked denoising autoencoder (SDAE)
        std::cout << "Pretrain an SAE" << std::endl;
        ff::Arch_t c(2UL);
        c[0] = 784;
        c[1] = 100;
//    ff::Arch_t c(3UL);
//    c[0] = 784;
//    c[1] = 3000;
//    c[2] = 500;
        std::cout << "c = " << c << "numel(c) = " << numel(c) << std::endl;
        Opts opts;
//    opts.numpochs = 2;//50
        std::cout << "numpochs = " << opts.numpochs << std::endl;


        // Divide inputs into para groups.
        std::vector<int> iRandVec;
        randperm(d.train_x->rows(),iRandVec);
        int baseSize = d.train_x->rows() / (PARAGRANULARITY * opts.batchsize);
        std::vector<FMatrix_ptr> train_x_pvec;
        std::cout << "Divide inputs:";
        for(int i = 0; i < PARAGRANULARITY; i++)
        {
            std::cout << " " << i;
            int pSize = baseSize * opts.batchsize;
            if(i == PARAGRANULARITY - 1)//add the remains to the last group
                pSize += d.train_x->rows() % (PARAGRANULARITY * opts.batchsize);
            FMatrix para_x(pSize,d.train_x->columns());
            for(int r = 0; r < pSize; ++r)//randperm()
                row(para_x,r) = row(*d.train_x,iRandVec[i * baseSize * opts.batchsize + r]);
            train_x_pvec.push_back(std::make_shared<FMatrix>(para_x));
        }
        std::cout << std::endl;

        ff::SAE sae_master(c);
        std::vector<SAE_ptr> sae_pvec;
        for(int i = 0; i < PARAGRANULARITY; i++)
        {
            std::cout << i << ":" << train_x_pvec[i]->rows() << " , " << train_x_pvec[i]->columns() << std::endl;
            ff::SAE sae(c);
            //check if sae structure is correct
            std::vector<FBNN_ptr> & m_oAEs = sae.get_m_oAEs();
            for(int i = 0; i < m_oAEs.size(); i++)
            {
                std::vector<FMatrix_ptr> & m_oWs = m_oAEs[i]->get_m_oWs();
                std::vector<FMatrix_ptr> & m_oVWs = m_oAEs[i]->get_m_oVWs();
                std::vector<FMatrix_ptr> & m_oPs = m_oAEs[i]->get_m_oPs();
                std::cout << "SAE[" << i << "]:" << std::endl;
            }
            sae_pvec.push_back(std::make_shared<SAE>(sae));
        }
        if(!isPara)
        {
            for(int i = 0; i < PARAGRANULARITY; i++)
            {
                std::cout << "start train SAE " << i << std::endl;
                sae_pvec[i]->SAETrain(*train_x_pvec[i],opts,std::make_shared<SAE>(sae_master));
            }
        }
        else{
//         tbb::task_group tg;
//         for(int i = 0; i < PARAGRANULARITY; i++)
//         {
//             tg.run([&sae_pvec,i,&train_x_pvec,&opts,&sae_master]() {
//                 sae_pvec[i]->SAETrain(*train_x_pvec[i],opts,std::make_shared<SAE>(sae_master));
//             });
//         }
//         tg.wait();
            ff::paragroup pg;
            for(int i = 0; i < PARAGRANULARITY; i++)
            {
                ff::para<void> p;
                p([&sae_pvec,i,&train_x_pvec,&opts,&sae_master]() {
                    sae_pvec[i]->SAETrain(*train_x_pvec[i],opts,std::make_shared<SAE>(sae_master));
                });
                pg.add(p);
            }
            ff_wait(all(pg));
        }

        //Use the SDAE to initialize a FFNN
        std::cout << "Train an FFNN" << std::endl;
ff:Arch_t cn(3UL);
        cn[0] = 784;
        cn[1] = 100;
        cn[2] = 10;
//    ff:Arch_t cn(4UL);
//    cn[0] = 784;
//    cn[1] = 3000;
//    cn[2] = 500;
//    cn[3] = 10;
        std::cout << "cn = " << cn << "numel(cn) = " << numel(cn) << std::endl;
//    ff::FBNN nn(cn,"sigm",0.1);
        ff::FBNN nn(cn,"sigm",1);
//    opts.numpochs = 3;//200
        //check if nn structure is correct
        std::vector<FMatrix_ptr> & m_oWs = nn.get_m_oWs();
        std::vector<FMatrix_ptr> & m_oVWs = nn.get_m_oVWs();
        std::vector<FMatrix_ptr> & m_oPs = nn.get_m_oPs();
        for(int j = 0; j < m_oWs.size(); j++) {
            std::cout << "W[" << j << "] = {" << m_oWs[j]->rows() << ", " << m_oWs[j]->columns() << "}" << std::endl;
            if(!m_oVWs.empty())
                std::cout << "vW[" << j << "] = {" << m_oVWs[j]->rows() << ", " << m_oVWs[j]->columns() << "}" << std::endl;
            if(!m_oPs.empty())
                std::cout << "P[" << j << "] = {" << m_oPs[j]->rows() << ", " << m_oPs[j]->columns() << "}" << std::endl;
        }
//     *m_oWs[0] = *(m_oAEs[0]->get_m_oWs())[0];//nn.W{1} = sae.ae{1}.W{1};

        for(int i = 0; i < m_oWs.size() - 1; i++)
        {
            *m_oWs[i] = *(sae_master.get_m_oAEs()[i]->get_m_oWs())[0];//nn.W{i} = sae.ae{i}.W{1};
        }


//     std::cout << "d.train_x = (" << d.train_x->rows() << "," << d.train_x->columns() << ")" << std::endl;

        //Train the FFNN
        nn.train(*d.train_x,*d.train_y,opts);
        double error = nn.nntest(*d.test_x,*d.test_y);
        std::cout << "test error = " << error << std::endl;
        if(error >= 0.16)
            std::cout << "Too big error!" << std::endl;  
    });
    std::cout << "Total elapsed time: " << elapsedTime << "s" << std::endl;

    return 0;
}
