#include "utils/matlib.h"

using namespace ff;

int main(int argc, char *argv[])
{
  FMatrix m(2, 2);
  for (int i = 0; i < m.rows(); ++i)
    for(int j = 0; j < m.columns(); ++j)
    {
      m(i, j) = i*j * 0.3;
    }
  std::cout<<" m = \n" <<m<<std::endl;
  return 0;
}
