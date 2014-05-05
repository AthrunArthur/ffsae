#ifndef FFSAE_DTYPE_TYPE_H_
#define FFSAE_DTYPE_TYPE_H_

#include <blaze/Math.h>

namespace ff
{
  typedef blaze::DynamicMatrix<double, blaze::rowMajor> FMatrix;

  template <class T>
  struct is_matrix{};

  template <>
  struct is_matrix<FMatrix>{const static bool value = true;}
}

#endif
