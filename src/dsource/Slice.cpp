#include "dsource/Slice.h"
#include <matio.h>
#include "common/scope_guard.h"

namespace ff{
  Slice::Slice(const uint8_t * pdata, size_t len, int actual_number)
    : m_pData(nullptr)
    , m_iDataLen(len)
    , m_iActualNumber(actual_number)
  {
        m_pData = new uint8_t[len];
        assert(m_pData != nullptr && "Slice::Slice() malloc error!");
        memcpy(m_pData, pdata, len);
  }

  Slice::~Slice()
  {
    delete[] m_pData;
  }

  uint8_t & Slice::operator[](int i)
  {
    assert(i < m_iDataLen && "index out of range");
    return m_pData[i];
  }

  Slices_t Slice::getAllSlices()
  {
    const char *fileName = "../data/mnist_uint8.mat";
    Slices_t res ;
    mat_t *mat = nullptr;
    scope_guard _l([&mat, fileName](){
        mat = Mat_Open(fileName, MAT_ACC_RDONLY);},
        [&mat](){
        Mat_Close(mat);
        });
    if(mat)
    {
      matvar_t * var = 0;
      matvar_t * xvar = 0;
      matvar_t * yvar = 0;
      while((var = Mat_VarReadNextInfo(mat)) != NULL){
        if(strcmp(var->name, "train_x") != 0)
        {
          xvar = Mat_VarRead(mat, var->name);
        }
        else if (strcmp(var->name, "train_y") != 0)
        {
          yvar = Mat_VarRead(mat, var->name);
        }
        if (xvar != 0 && yvar != 0)
        {
          int scount = xvar->dims[0];
          int pcount = xvar->dims[1];
          uint8_t * pData = static_cast<uint8_t *>(xvar->data);
          uint8_t * yData = static_cast<uint8_t *>(yvar->data);
          for (int k = 0; k < scount; ++k)
          {
            std::vector<uint8_t> pd;
            for(int i = 0; i < pcount; i ++)
            {
              pd.push_back(pData[scount * i + k]);
            }
            int ncount = yvar->dims[1];
            int num = 0;
            
            for(int i = 0; i < ncount; ++i)
            {
              int tt = yData[scount * i + k];
              if(tt!=0)
              {
                num = tt;
                break;
              }
            }
            Slice_ptr p = std::make_shared<Slice>(
                pd.data(), pd.size(), num);
           res.push_back(p); 
          }
        }

    }//end while
  }//end if
        return res;
  }//end getAllSlice()
};//end namespace ff
