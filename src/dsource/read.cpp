#include "dsource/read.h"
#include "common/common.h"
#include "common/scope_guard.h"
#include <matio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>


namespace ff
{

  static FMatrix_ptr read_matrix_in_mat(mat_t * mat, const char *varname)
  {
    matvar_t  * tvar = Mat_VarRead(mat, varname);
    FMatrix_ptr res;

    return res;
  }
  TData         read_data()
  {
    const char * fileName = "../data/mnist_unit8.mat";
    TData res;
    mat_t *mat = nullptr;
    scope_guard _l([&mat, fileName](){
      mat = Mat_Open(fileName, MAT_ACC_RDONLY);
      },
    [&mat](){Mat_Close(mat); });
    if(!mat){
      return res;
    }  
    matvar_t *var = 0;
    matvar_t *tvar = 0;
    while((var = Mat_VarReadNextInfo(mat)) != nullptr){
      if(strcmp(var->name, "train_x") == 0)
      {
        res.train_x = read_matrix_in_mat(mat, var->name);
      }
      else if(strcmp(var->name, "train_y") == 0)
      {
        
      }

    }
    return res;
  }
};//end namespace ff
