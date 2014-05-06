/*
 * This shall be header file for SAE
 */
#ifndef FFSAE_SAE_SAE_H_
#define FFSAE_SAE_SAE_H_
#include "common/common.h"
#include "utils/matlib.h"
#include "nn/fbnn.h"


namespace ff
{
  class SAE
  {
    public:
        SAE(const FMatrix & m)
        {
          for(int i = 1; i < numel(m); ++i)
          {
            Arch_t t;
            t[0] = m(0, i-1);
            t[1] = m(0, i);
            t[2] = m(0, i-1);
            m_oAEs.push_back(std::make_shared<FBNN>(t));
          }
        }

    protected:
        std::vector<FBNN_ptr>        m_oAEs;
  };//end class SAE
};//end namespace ff

#endif
