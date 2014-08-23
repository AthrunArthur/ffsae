#include "sae/sae.h"
#include "dsource/divide.h"
#include <time.h>
#include <boost/any.hpp>

namespace ff{
  extern "C" boost::any SAE_create(void);
  extern "C" bool SAE_run(boost::any sae_pointer,std::string data_dir);
  extern "C" void SAE_delete(boost::any sae_pointer); 
  extern "C" void train_NN(boost::any sae_pointer,std::string input_file = "");
  
};//end namespace ff