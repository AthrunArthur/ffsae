#include "dsource/Slice.h"
#include <iostream>

int main(int argc, const char *argv[])
{
  auto s = ff::Slice::getAllSlices();
  int count = 0;
  for(auto pss : s)
  {
    ff::Slice & ss = *(pss.get());
       int dim = static_cast<int>(sqrt(ss.len()));
       std::cout<<"ss len() : "<<ss.len()<<std::endl;
       std::cout<<"************************* "<<ss.num()<<std::endl;
      for(int i = 0; i < dim; ++i)
      {
        for(int j = 0; j < dim; ++j)
        {
          std::cout<<static_cast<int>(ss[i*dim + j] != 0)<< " ";
        }
        std::cout<<std::endl;
      } 
    count ++;
    if(count >= 20)
	break;
  }
  return 0;
}
