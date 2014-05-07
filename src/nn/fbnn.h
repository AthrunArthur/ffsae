#ifndef FFSAE_NN_FBNN_H_
#define FFSAE_NN_FBNN_H_

#include "common/common.h"
#include "arch.h"
#include "utils/matlib.h"

namespace ff
{
  /* This class represents Feedforward Backpropagate Neural Network
   */

  class FBNN{
    public:
      FBNN(const Arch_t & arch)
       : m_oArch(arch)
         , m_iN(numel(m_oArch))
         , m_strActivationFunction("tanh_opt")
         , m_strOutput("sigm")
      {
        for(int i = 1; i < m_iN; ++i)
        {
          FMatrix f = (rand(m_oArch[i], m_oArch[i-1] + 1) - 0.5) * 2 * 4 * sqrt(6/(m_oArch[i] + m_oArch[i-1]));//based on nnsetup.m
          m_oWs.push_back(std::make_shared<FMatrix>(f));
          FMatrix z = zeros(f.rows(), f.columns());
          m_oVWs.push_back(std::make_shared<FMatrix>(z));
          FMatrix p = zeros(1, m_oArch[i]);
          m_oPs.push_back(std::make_shared<FMatrix>(p));
        }
        
      }
      FBNN(const FBNN & p) = delete;
      FBNN & operator =(const FBNN & p) = delete;
      
      std::vector<FMatrix_ptr> & get_m_oWs(void){return m_oWs;};
      std::vector<FMatrix_ptr> & get_m_oVWs(void){return m_oVWs;};
      std::vector<FMatrix_ptr> & get_m_oPs(void){return m_oPs;};

      protected:
        
      const Arch_t &    m_oArch;
      int         m_iN;
      std::string       m_strActivationFunction;
      static constexpr int         m_iLearningRate=2;
      static constexpr double      m_fMomentum = 0.5;
      static constexpr double      m_fScalingLearningRate= 1;
      static constexpr double      m_fWeithtPenaltyL2 = 0;
      static constexpr double      m_fNonSparsityPenalty = 0;
      static constexpr double      m_fSparsityTarget = 0.05;
      static constexpr double      m_fInputZeroMaskedFraction = 0;
      static constexpr double      m_fDropoutFraction = 0;
      static constexpr double      m_fTesting = 0;
      std::string m_strOutput;

      std::vector<FMatrix_ptr>  m_oWs;
      std::vector<FMatrix_ptr>  m_oVWs;
      std::vector<FMatrix_ptr>  m_oPs;

    
  };//end class FBNN
  typedef std::shared_ptr<FBNN> FBNN_ptr;
}//end namespace ff

#endif
