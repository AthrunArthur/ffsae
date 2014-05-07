#include "sae.h"

namespace ff
{
  void SAE::SAETrain(const Slices_t & trains)
  {
       size_t num_ae = m_oAEs.size();
      for( size_t i = 0; i < num_ae; ++i)
      {
        m_oAEs[i]->train(trains, trains);
        m_oAEs[i]->nnff(trains, trains);
      } 
  }
}//end namespace ff
