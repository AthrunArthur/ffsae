#include <iostream>
#include <blaze/Math.h>
using blaze::StaticVector;
using blaze::DynamicVector;
typedef blaze::DynamicMatrix<double, blaze::rowMajor> DMatrix;
// Instantiation of a static 3D column vector. The vector is directly
// initialized as
// // ( 4 -2 5 )
int main(int argc, char *argv[]) {
  StaticVector<double, 3UL> a(4, -2, 5);
  // // Instantiation of a dynamic 3D column vector. Via the subscript operator
  // the values are set to
  // // ( 2 5 -3 )
  DynamicVector<int> b(3UL);
  b[0] = 2;
  b[1] = 5;
  b[2] = -3;
  // // Adding the vectors a and b
  DynamicVector<double> c = a + b;
  
  c = a / 3;
  
  // // Printing the result of the vector addition
  std::cout << "c =\n" << c << "\n";  
  
  DMatrix m(3,4,6);
  std::cout << "m=\n" << m << std::endl;
  
  DMatrix m1(m);
  
  std::cout << m1 / 4 << std::endl;
//   std::cout << 3 / m << std::endl;//undefined
  
  return 0;
}
