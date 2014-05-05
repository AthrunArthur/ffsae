#include "utils/matlib.h"

using namespace ff;

int main(int argc, char *argv[])
{
  FMatrix m(2, 2);
  for (int i = 0; i < m.rows(); ++i)
    for(int j = 0; j < m.columns(); ++j)
    {
      m(i, j) = 1 + i*j * 0.3;
    }
  std::cout<<" m = \n" <<m<<std::endl;
  int a = 5;
  std::cout<<"is_matrix: true -- "<<is_matrix<FMatrix>::value<<std::endl;
  std::cout<<" tt : "<<is_one_matrix_one_arith<FMatrix, int>::value<<std::endl;
  FMatrix r1 = m + 5;
  FMatrix r2 = 10 + m;
  std::cout<<" r1 = \n" <<r1<<std::endl;
  std::cout<<" r2 = \n" <<r2<<std::endl;

  return 0;
}
