#pragma once

#include "common/common.h"
#include "dtype/type.h"

namespace ff
{
  struct TData
  {
        FMatrix_ptr train_x;
        FMatrix_ptr train_y;
        FMatrix_ptr test_x;
        FMatrix_ptr test_y;
  };//end struct TData

  TData read_data();
}
