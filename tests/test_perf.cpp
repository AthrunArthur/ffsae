#include "sae/sae.h"
#include "dsource/read.h"
#include <time.h>
#include "nn/opt.h"
#include "utils/utils.h"

using namespace ff;
using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    TData d = read_data();

    int t1 = count_elapse_microsecond([d]{
    *d.train_x = (*d.train_x) / 255;
    *d.test_x = (*d.test_x) / 255;
        });
    std::cout<<"t1: "<< t1<<std::endl;

    int t2 = count_elapse_microsecond([d]{
        for(int i = 0; i < d.train_x->rows(); ++i)
            for(int j = 0; j < d.train_x->columns(); ++j)
            {
                d.train_x->operator ()(i, j) /= 255;
            }


        for(int i = 0; i < d.train_y->rows(); ++i)
            for(int j = 0; j < d.train_y->columns(); ++j)
            {
                d.train_y->operator ()(i, j) /= 255;\
            }

    });
    blaze::sse_double_t t;
    std::cout<<"t2 : "<<t2<<std::endl;
    return 0;
}
