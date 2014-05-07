#include "dsource/read.h"

using namespace ff;
int main(int argc, char *argv[])
{
  TData d = read_data();
  std::cout<<"train_x : "<<std::endl;
  std::cout<<"\t rows: "<<d.train_x->rows()<<std::endl;
  std::cout<<"\t cols: "<<d.train_x->columns()<<std::endl;
  std::cout<<"train_y : "<<std::endl;
  std::cout<<"\t rows: " <<d.train_y->rows()<<std::endl;
  std::cout<<"\t cols: "<<d.train_y->columns() <<std::endl;
  return 0;
}
