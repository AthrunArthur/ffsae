#include "sae/sae.h"
#include "dsource/read.h"
#include <time.h>
#include "nn/opt.h"
#include "utils/utils.h"
#include "utils/matlib.h"

using namespace ff;
using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    TData d = read_data();
//     FMatrix res1 = *d.train_x,res2 = * d.test_x;
    FMatrix res1,res2;
    
    std::cout << "test assign :" << std::endl;
    int t1 = count_elapse_microsecond([d,&res1,&res2]{
      res1 = *d.train_x;
      res2 = *d.test_x;
// 	 FMatrix res = *d.train_x;
    });
    std::cout << "empty assign :\t" << t1 << std::endl;
    int t2 = count_elapse_microsecond([d,&res1,&res2]{
      res1 = *d.train_x;
      res2 = *d.test_x;
    });
    std::cout << "same size assign :\t" << t2 << std::endl;
    res1 = FMatrix();
    res2 = FMatrix();
    int t3 = count_elapse_microsecond([d,&res1,&res2]{
      res1.resize(d.train_x->rows(),d.train_x->columns());
      res2.resize(d.test_x->rows(),d.test_x->columns());
      res1 = *d.train_x;
      res2 = *d.test_x;
    });
    std::cout << "resize and assign :\t" << t3 << std::endl;
    
    int t4 = count_elapse_microsecond([d]{
      FMatrix res3(d.train_x->rows(),d.train_x->columns());
      FMatrix res4(d.test_x->rows(),d.test_x->columns());
      res3 = *d.train_x;
      res4 = *d.test_x;
    });
    std::cout << "initial and assign :\t" << t4 << std::endl;
    
    int t5 = count_elapse_microsecond([d]{
      FMatrix res3(d.train_x->rows(),d.train_x->columns());
      FMatrix res4(d.test_x->rows(),d.test_x->columns());
    });
    std::cout << "initial matrix :\t" << t5 << std::endl;
    
    std::cout << "res1: " << res1.rows() << "," << res1.columns() << std::endl;
    std::cout << "res2: " << res2.rows() << "," << res2.columns() << std::endl;
    
    std::cout << "test / :" << std::endl;
    t1 = count_elapse_microsecond([d,&res1,&res2]{
    res1 = (*d.train_x) / 255;
    res2 = (*d.test_x) / 255;
        });
    std::cout<<"blaze :\t"<< t1<<std::endl;

    t2 = count_elapse_microsecond([d,&res1,&res2]{
        for(int i = 0; i < d.train_x->rows(); ++i)
            for(int j = 0; j < d.train_x->columns(); ++j)
            {
                res1(i,j) = d.train_x->operator ()(i, j) / 255;
            }


        for(int i = 0; i < d.test_x->rows(); ++i)
            for(int j = 0; j < d.test_x->columns(); ++j)
            {
                res2(i,j) = d.test_x->operator ()(i, j) / 255;
            }

    });
//     blaze::sse_double_t t;
    std::cout<<"bit wise / :\t"<<t2<<std::endl;
    
    t3 = count_elapse_microsecond([d,&res1,&res2]{
        res1 = div(*d.train_x,255);
	res2 = div(*d.test_x,255);
    });
    std::cout<<"matlib :\t"<<t3<<std::endl;
    
    //test * & mul
    std::cout << "test * :" << std::endl;
    t1 = count_elapse_microsecond([d,&res1,&res2]{
    res1 = (*d.train_x) * 3;
    res2 = (*d.test_x) * 3;
        });
    std::cout<<"blaze :\t"<< t1<<std::endl;

    t2 = count_elapse_microsecond([d,&res1,&res2]{
        res1 = mul(*d.train_x,3);
	res2 = mul(*d.test_x,3);
    });
    std::cout<<"matlib :\t"<<t2<<std::endl;
    
    //test -
    std::cout << "test - " << std::endl;
    t1 = count_elapse_microsecond([d,&res1,&res2]{
      res1 = (*d.train_x) - 3;
      res2 = (*d.test_x) - 3;
        });
    std::cout<<"matlib :\t"<< t1<<std::endl;

    t2 = count_elapse_microsecond([d,&res1,&res2]{
        res1 = (*d.train_x) - FMatrix(d.train_x->rows(),d.train_x->columns(),3);
	res2 = (*d.test_x) - FMatrix(d.test_x->rows(),d.test_x->columns(),3);
    });
    std::cout<<"blaze matrix :\t"<<t2<<std::endl;
    
    t3 = count_elapse_microsecond([d,&res1,&res2]{
        for(int i = 0; i < d.train_x->rows(); ++i)
            for(int j = 0; j < d.train_x->columns(); ++j)
            {
                res1(i,j) = d.train_x->operator ()(i, j) - 3;
            }


        for(int i = 0; i < d.test_x->rows(); ++i)
            for(int j = 0; j < d.test_x->columns(); ++j)
            {
                res2(i,j) = d.test_x->operator ()(i, j) - 3;
            }

    });
    std::cout<<"bit wise - : "<<t3<<std::endl;
    
    return 0;
}
