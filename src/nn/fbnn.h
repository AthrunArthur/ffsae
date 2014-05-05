#ifndef FFSAE_NN_FBNN_H_
#define FFSAE_NN_FBNN_H_

#include "common/common.h"
#include "arch.h"

namespace ff
{
  /* This class represents Feedforward Backpropagate Neural Network
   */

  class FBNN{
    public:
      FBNN(const Arch_t & arch)
       : m_oArch(arch)
         , m_iN(arch.size())
      {
      }
      FBNN(const FBNN & p) = delete;
      FBNN & operator =(const FBNN & p) = delete;

      protected:
        
      const Arch_t &    m_oArch;
      int         m_iN;
      static const std::string       m_strActivationFunction = "tanh_opt";
      static const int         m_iLearningRate=2;
      static const double      m_fMomentum = 0.5;
      static const double      m_fScalingLearningRate= 1;
      static const double      m_fWeithtPenaltyL2 = 0;
      static const double      m_fNonSparsityPenalty = 0;
      static const double      m_fSparsityTarget = 0.05;
      static const double      m_fInputZeroMaskedFraction = 0;
      static const double      m_fDropoutFraction = 0;
      static const double      m_fTesting = 0;
      static const double      m_strOutput = "sigm";

    
  };//end class FBNN
}//end namespace ff

#endif
