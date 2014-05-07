/*
 * This shall be header file for SAE
 */
#ifndef FFSAE_SAE_SAE_H_
#define FFSAE_SAE_SAE_H_
#include "common/common.h"
#include "utils/matlib.h"
#include "nn/fbnn.h"
#include "dsource/Slice.h"

namespace ff
{
  class SAE
  {
    public:
        SAE(const FMatrix & m)
          : m_strActivationFunction("sigm")
          , m_fLearningRate(1)
          , m_fInputZeroMaskedFraction(0.5)
        {
          for(size_t i = 1; i < numel(m); ++i)
          {
            Arch_t t;
            t[0] = m(0, i-1);
            t[1] = m(0, i);
            t[2] = m(0, i-1);
            m_oAEs.push_back(std::make_shared<FBNN>(t));
          }
        }

        void    SAETrain(const Slices_t & trains);

    protected:
        std::vector<FBNN_ptr>        m_oAEs;
        std::string    m_strActivationFunction;
        double          m_fLearningRate;
        double          m_fInputZeroMaskedFraction;
  };//end class SAE
};//end namespace ff

#endif
