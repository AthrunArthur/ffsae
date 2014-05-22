#include "dsource/read.h"
#include <time.h>
#include <cstdlib>

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
  std::cout<<"test_x : "<<std::endl;
  std::cout<<"\t rows: "<<d.test_x->rows()<<std::endl;
  std::cout<<"\t cols: "<<d.test_x->columns()<<std::endl;
  std::cout<<"test_y : "<<std::endl;
  std::cout<<"\t rows: " <<d.test_y->rows()<<std::endl;
  std::cout<<"\t cols: "<<d.test_y->columns() <<std::endl;
  
  //Randomly test different rows
  srand(time(NULL));
  for(int i = 0; i < 1; i++)
  {
    //Get random row number
    int train_row = rand() % (d.train_x->rows());
    int test_row = rand() % (d.test_x->rows());
    
    //train_x row
    std::cout << "\ntrain_x(" << train_row + 1 << ",:)" << std::endl;//+1 for testing in matlab
    for(int j = 0; j < d.train_x->columns(); j++){
      if(j % 14 == 0)
	std::cout << "\nColumns " << j+1 << " through " << j + 14 << ":" << std::endl;//+1 for testing in matlab
      std::cout << (*d.train_x)(train_row,j) << "\t";
    }
    std::cout << std::endl;
    
    //train_y row
    std::cout << "\ntrain_y(" << train_row + 1 << ",:)" << std::endl;//+1 for testing in matlab
    for(int j = 0; j < d.train_y->columns(); j++){
      std::cout << (*d.train_y)(train_row,j) << "\t";
    }
    std::cout << std::endl;
    
    //test_x row
    std::cout << "\ntest_x(" << test_row + 1 << ",:)" << std::endl;//+1 for testing in matlab
    for(int j = 0; j < d.test_x->columns(); j++){
      if(j % 14 == 0)
	std::cout << "\nColumns " << j+1 << " through " << j + 14 << ":" << std::endl;//+1 for testing in matlab
      std::cout << (*d.test_x)(test_row,j) << "\t";
    }
    std::cout << std::endl;
    
    //test_y row
    std::cout << "\ntest_y(" << test_row + 1 << ",:)" << std::endl;//+1 for testing in matlab
    for(int j = 0; j < d.test_y->columns(); j++){
      std::cout << (*d.test_y)(test_row,j) << "\t";
    }
    std::cout << std::endl;
  }
  
  
  return 0;
}
