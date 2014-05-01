#ifndef FFSAE_DSOURCE_SLICE_H_
#define FFSAE_DSOURCE_SLICE_H_
#include "common/common.h"


namespace ff{
  /*This class is used to represent a data for SAE,
   * In particular, a matrix for hand-writing pixels, and the number */

  class Slice;
  typedef std::shared_ptr<Slice> Slice_ptr;
  typedef std::vector<Slice_ptr> Slices_t;

  class Slice{
    public:
      Slice(const uint8_t * pdata, size_t len, int actual_number);
      Slice(const Slice & p) = delete;
      Slice & operator=(const Slice & p) = delete;

      virtual ~Slice();

      uint8_t &   operator[](int i);

      size_t      len() const{return m_iDataLen;}
      int         num() const{return m_iActualNumber;}
      void        set_num(int actual_number){m_iActualNumber = actual_number;}
        

      static  Slices_t  getAllSlices();
    protected:
      uint8_t * m_pData;
      size_t  m_iDataLen;
      int       m_iActualNumber;
  };//end class Slice

  
};//end namespace ff

#endif
