#include "sae.h"

namespace ff
{
  SAE::SAE(const Arch_t & arch)
      : m_strActivationFunction("sigm")
      , m_fLearningRate(1)
      , m_fInputZeroMaskedFraction(0.5)
  {
      std::cout << "SAE initialize!" << std::endl;
      for(size_t i = 1; i < numel(arch); ++i)
      {
	  Arch_t t(3UL);
	  t[0] = arch[i-1];
	  t[1] = arch[i];
	  t[2] = arch[i-1];
	  m_oAEs.push_back(std::make_shared<FBNN>(t,m_strActivationFunction,m_fLearningRate,m_fInputZeroMaskedFraction));
      }
      std::cout << "Finish initialize!" << std::endl;
  }
  void SAE::SAETrain(FMatrix & train_x)
  {
      size_t num_ae = m_oAEs.size();
      FMatrix & x = train_x;
      for( size_t i = 0; i < num_ae; ++i)
      {
	std::cout << "Training AE " << i+1 << " / " << num_ae << std::endl;
        m_oAEs[i]->train(x, x);
        m_oAEs[i]->nnff(x, x);
	x = *(m_oAEs[i]->get_m_oAs())[1];
	x = delPreColumn(x);
      } 
  }
}//end namespace ff
