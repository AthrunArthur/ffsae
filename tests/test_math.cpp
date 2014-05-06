#include "utils/math.h"
#include <time.h>
#include <cstdlib>

using namespace ff;

int main(int argc, char *argv[])
{
    srand(time(NULL));//必须要初始化种子，否则始终生成相同结果

    FMatrix m(2, 2);
    for (int i = 0; i < m.rows(); ++i)
        for(int j = 0; j < m.columns(); ++j)
        {
            m(i, j) = 1 + i*j * 0.3;
        }
    std::cout << " m = \n" << m << std::endl;

    //sigm(double)
    std::cout << "sigm(5) = " << sigm(5) << std::endl;
    //sigm(FMatrix)
    std::cout << "sigm(m) = \n" << sigm(m) << std::endl;

    //sigmrnd(double)
    std::cout << "sigmrnd(0.2) = " << sigmrnd(0.2) << std::endl;
    //sigmrnd(FMatrix)
    std::cout << "sigmrnd(m) = \n" << sigmrnd(m) << std::endl;

    //softmax(double)
    double d_row[] = {1,2,3,4,5};
    softmax(d_row,5);
    std::cout << "softmax(1 to 5):\t";
    for(int i = 0; i < 5; i++)
        std::cout << d_row[i] << '\t';
    std::cout << std::endl;
    //softmax(FMatrix)
    std::cout << "softmax(m) = \n" << softmax(m) << std::endl;

    //tanh_opt(double)
    std::cout << "tanh_opt(5) = " << tanh_opt(5) << std::endl;
    //tanh_opt(FMatrix)
    std::cout << "tanh_opt(m) = \n" << tanh_opt(m) << std::endl;

    return 0;
}
