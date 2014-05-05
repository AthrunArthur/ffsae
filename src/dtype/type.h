#ifndef FFSAE_DTYPE_TYPE_H_
#define FFSAE_DTYPE_TYPE_H_

#include <blaze/Math.h>

namespace ff
{
  typedef blaze::DynamicMatrix<double, blaze::rowMajor> FMatrix;
  typedef std::shared_ptr<FMatrix> FMatrix_ptr;

  template <class T>
  struct is_matrix{const static bool value=false;};

  template <>
  struct is_matrix<FMatrix>{const static bool value = true;};
}

#endif
