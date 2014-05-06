#ifndef FFSAE_NN_NN_ARCH_H_
#define FFSAE_NN_NN_ARCH_H_

#include "dtype/type.h"

namespace ff{
//  typedef FMatrix Arch_t;
  
  typedef blaze::StaticVector<int, 3UL, blaze::columnVector> Arch_t;
  size_t     numel(const Arch_t & a)
    {
      return a.size();
    }

}
;//end namespace ff
#endif
