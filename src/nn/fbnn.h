#ifndef FFSAE_NN_FBNN_H_
#define FFSAE_NN_FBNN_H_

#include "common/common.h"
#include "nn/arch.h"
#include "nn/opt.h"
#include "utils/math.h"
#include "nn/loss.h"

namespace ff
{
  /* This class represents Feedforward Backpropagate Neural Network
   */

  class FBNN{
    public:
      FBNN(const Arch_t & arch, std::string activeStr = "tanh_opt", int learningRate = 2, double zeroMaskedFraction = 0, bool testing = false, std::string outputStr = "sigm");
      FBNN(const FBNN & p) = delete;
      FBNN & operator =(const FBNN & p) = delete;
      
      std::vector<FMatrix_ptr> & get_m_oWs(void){return m_oWs;};
      std::vector<FMatrix_ptr> & get_m_oVWs(void){return m_oVWs;};
      std::vector<FMatrix_ptr> & get_m_oPs(void){return m_oPs;};
      std::vector<FMatrix_ptr> & get_m_oAs(void){return m_oAs;};

      void      train(const FMatrix & train_x, const FMatrix & train_y, const Opts & opts, const FMatrix & valid_x, const FMatrix & valid_y);

      void      train(const FMatrix & train_x, const FMatrix & train_y , const Opts & opts);
      double    nnff(const FMatrix & x, const FMatrix & y);
      void      nnbp(void);
      void	nnapplygrads(void);
      void	nneval(Loss & loss,const FMatrix & train_x, const FMatrix & train_y, const FMatrix & valid_x, const FMatrix & valid_y);
      void	nneval(Loss & loss,const FMatrix & train_x, const FMatrix & train_y);
      double	nntest(const FMatrix & x, const FMatrix & y);
      void	nnpredict(const FMatrix & x, const FMatrix & y, FColumn & labels);
      
      protected:
        
      const Arch_t &    m_oArch;
      int         m_iN;
      std::string       m_strActivationFunction;
      int         m_iLearningRate;//shall be changed during train()
//       static constexpr int         m_iLearningRate=2;
      static const double      m_fMomentum;
      static const double      m_fScalingLearningRate;
      static const double      m_fWeithtPenaltyL2;
      static const double      m_fNonSparsityPenalty;
      static const double      m_fSparsityTarget;
      double      m_fInputZeroMaskedFraction;
//       static constexpr double      m_fInputZeroMaskedFraction = 0;
      static const double      m_fDropoutFraction;
//       static constexpr double      m_fTesting = 0;
      bool      m_fTesting;
      std::string m_strOutput;

      std::vector<FMatrix_ptr>  m_oWs;
      std::vector<FMatrix_ptr>  m_oVWs;
      std::vector<FMatrix_ptr>  m_oPs;
      std::vector<FMatrix_ptr>  m_oAs;
      std::vector<FMatrix_ptr>  m_odOMs;//dropOutMask
      std::vector<FMatrix_ptr>  m_odWs;
      
      
      FMatrix_ptr  m_oLp;//Loss matrix
      FMatrix_ptr  m_oEp;//Error matrix
      

    
  };//end class FBNN
  typedef std::shared_ptr<FBNN> FBNN_ptr;
}//end namespace ff

#endif
