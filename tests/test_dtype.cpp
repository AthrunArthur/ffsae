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
  
  //test blaze row()
  std::cout << "row(m,0) = \n" << row(m,0) << std::endl;
  std::cout << "row(m,1) = \n" << row(m,1) << std::endl;
  
  //test blaze column()
  std::cout << "column(m,0) = \n" << column(m,0) << std::endl;
  std::cout << "column(m,1) = \n" << column(m,1) << std::endl;
  
  //test empty matrix
  FMatrix m0;//FMatrix m0(0,0);
  std::cout << "empty matrix m0 = \n" << m0 << std::endl;
  std::cout << "FMatrix() = \n" << FMatrix() << std::endl;
  std::cout << "rows = " << m0.rows() << ", columns = " << m0.columns() << std::endl;
  
  //test submatrix()
  FMatrix m1(3,3,0.5);
  submatrix(m1,1UL,1UL,2UL,2UL) = m;
  std::cout << "m1 = \n" << m1 << std::endl;
  
  FMatrix m2(3,2,0.6);
  //test matrix trans()
  std::cout << "m2 = \n" << m2 << std::endl;
  std::cout << "trans matrix = \n" << trans(m2) << std::endl;
  
  //test clear()
  clear(m);
  std::cout << "After clear(), m.rows() = " << m.rows() << std::endl;
  
  //test FMatrix_ptr
  FMatrix_ptr m_ptr = std::make_shared<FMatrix>(FMatrix(0,0));
  std::cout << "*m_ptr = \n" << *m_ptr << std::endl;
  *m_ptr = m2;
  std::cout << "*m_ptr = \n" << *m_ptr << std::endl;
  
  //test std::vector<FMatrix_ptr>
  std::vector<FMatrix_ptr> m_ptrs;
  for(int i = 0; i < 3; i++)
    m_ptrs.push_back(std::make_shared<FMatrix>(FMatrix(0,0)));
  *m_ptrs[1] = m1;
  *m_ptrs[2] = m2;
  for(int i = 0; i < 3; i++)
    std::cout << "*m_ptrs[" << i << "] = \n" << *m_ptrs[i] << std::endl;
  
  return 0;
}
