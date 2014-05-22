/*
 * This shall be header file for SAE
 */
#ifndef FFSAE_SAE_SAE_H_
#define FFSAE_SAE_SAE_H_
#include "common/common.h"
#include "nn/fbnn.h"

namespace ff
{
  class SAE
  {
    public:
        SAE(const Arch_t & arch);
//           : m_strActivationFunction("sigm")
//           , m_fLearningRate(1)
//           , m_fInputZeroMaskedFraction(0.5)
//         {
// 	  std::cout << "SAE initialize!" << std::endl;
//           for(size_t i = 1; i < numel(arch); ++i)
//           {
//             Arch_t t(3UL);
//             t[0] = arch[i-1];
//             t[1] = arch[i];
//             t[2] = arch[i-1];
//             m_oAEs.push_back(std::make_shared<FBNN>(t,m_strActivationFunction,m_fLearningRate,m_fInputZeroMaskedFraction));
//           }
//           std::cout << "Finish initialize!" << std::endl;
//         }

        void    SAETrain(FMatrix & train_x);
	std::vector<FBNN_ptr> & get_m_oAEs(void){return m_oAEs;};

    protected:
        std::vector<FBNN_ptr>        m_oAEs;
        std::string    m_strActivationFunction;
        double          m_fLearningRate;
        double          m_fInputZeroMaskedFraction;
  };//end class SAE
};//end namespace ff

#endif
