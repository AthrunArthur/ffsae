/*
 * This shall be header file for mathmatic
 */
#ifndef FFSAE_UTILS_MATH_H_
#define FFSAE_UTILS_MATH_H_

#include <cmath>

namespace ff{
  double        sigm(const double & x);
  
  double        sigrnd(const double & x);

  double        softmax();

  double        tanh_opt();
}//end namespace ff
#endif
