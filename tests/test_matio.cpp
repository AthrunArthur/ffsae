#include <iostream>

#include <matio.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstring>



int main(int argc, char *argv[]) {
    const char *fileName = "../data/mnist_uint8.mat";
    mat_t *mat = Mat_Open(fileName, MAT_ACC_RDONLY);
    if (mat) {
        std::cout << "reading mat file..." << std::endl;
        matvar_t *var = 0;
        while((var = Mat_VarReadNextInfo(mat)) != NULL){
            if (strcmp(var->name, "train_x") != 0)
                continue;
            
            std::cout<<"name : " << var->name<<std::endl;
            matvar_t *matVar = Mat_VarRead(mat, var->name);
            
            std::cout<<"\tnbytes: "<<matVar->nbytes<<std::endl;
            std::cout<<"\tdata_size: "<<matVar->data_size<<std::endl;
            int scount = matVar->dims[0];
            int pcount = matVar->dims[1];
            uint8_t * pData = static_cast<uint8_t * >(matVar->data);
            int dim = static_cast<int>(sqrt(pcount));
            std::cout<<"dim : " <<dim <<std::endl;
            std::cout<<std::endl;
            for(int k = 0; k < 20; k++)
            {
                std::cout<<"********************"<<std::endl;
                std::vector<int> pd;
                for (int i = 0; i < pcount; i ++)
                {
                    pd.push_back(pData[scount*i + k]);
                }
                for(int i = 0; i< dim; ++i)
                {
                    for (int j = 0; j < dim; ++j)
                    {
                        std::cout<< static_cast<int>(pd[i*dim + j] != 0)<< " ";
                    }
                    std::cout<<std::endl;
                }
            }
        }
        std::cout << "closing mat file..." << std::endl;
        Mat_Close(mat);
        
    } else {
        std::cout << "Cannot open mat file..." << std::endl;
        return 1;
    }
    return 0;
}
