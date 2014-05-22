#include "sae/sae.h"
#include "dsource/read.h"

using namespace ff;

int main(int argc, char *argv[])
{
//     ff::FMatrix m(1, 2);
//     m(0, 0) = 784;
//     m(0, 1) = 100;
    
    ff::Arch_t m(3UL);
    m[0] = 784;
    m[1] = 100;
    m[2] = 10;
    
    std::cout << "m = " << m << std::endl; 
    std::cout << "numel(m) = " << numel(m) << std::endl;
    ff::SAE s(m);
    //need check if s is correct!!!
    std::vector<FBNN_ptr> & m_oAEs = s.get_m_oAEs();
    for(int i = 0; i < m_oAEs.size(); i++)
    {
	std::vector<FMatrix_ptr> & m_oWs = m_oAEs[i]->get_m_oWs();
	std::vector<FMatrix_ptr> & m_oVWs = m_oAEs[i]->get_m_oVWs();
	std::vector<FMatrix_ptr> & m_oPs = m_oAEs[i]->get_m_oPs();
	std::cout << "SAE[" << i << "]:" << std::endl;
	for(int j = 0; j < m_oWs.size(); j++){
	  std::cout << "W[" << j << "] = {" << m_oWs[j]->rows() << ", " << m_oWs[j]->columns() << "}" << std::endl;
	  std::cout << "vW[" << j << "] = {" << m_oVWs[j]->rows() << ", " << m_oVWs[j]->columns() << "}" << std::endl;
	  std::cout << "P[" << j << "] = {" << m_oPs[j]->rows() << ", " << m_oPs[j]->columns() << "}" << std::endl;
	}
    }
    
    TData d = read_data();
//     s.SAETrain(*d.train_x);
    s.SAETrain(FMatrix());

    return 0;
}
