#ifndef FFSAE_NN_OPT_H_
#define FFSAE_NN_OPT_H_

#include "common/common.h"

namespace ff
{
  typedef struct 
  {
    int numpochs = 1;
    int batchsize = 100;
  } Opts;
}

#endif
