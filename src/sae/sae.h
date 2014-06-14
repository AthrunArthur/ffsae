/*
 * This shall be header file for SAE
 */
#ifndef FFSAE_SAE_SAE_H_
#define FFSAE_SAE_SAE_H_
#include "common/common.h"
#include "nn/fbnn.h"

namespace ff
{
  class SAE;
  typedef std::shared_ptr<SAE> SAE_ptr;
  class SAE
  {
    public:
        SAE(const Arch_t & arch);
        void    SAETrain(const FMatrix & train_x, const Opts & opts, const SAE_ptr & pSAE = nullptr);
	std::vector<FBNN_ptr> & get_m_oAEs(void){return m_oAEs;};

    protected:
        std::vector<FBNN_ptr>        m_oAEs;
        std::string    m_strActivationFunction;
        double          m_fLearningRate;
        double          m_fInputZeroMaskedFraction;
  };//end class SAE
//   typedef std::shared_ptr<SAE> SAE_ptr;
};//end namespace ff

#endif
