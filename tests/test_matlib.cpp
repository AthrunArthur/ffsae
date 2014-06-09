#include "utils/matlib.h"
#include <time.h>
#include "dtype/type.h"

using namespace ff;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    
    //randperm
    std::cout << "randperm(60000) =";
    std::vector<int> iVector;
    randperm(60000,iVector);
    for(std::vector<int>::iterator it=iVector.begin(); it!=iVector.end(); ++it)
	std::cout << ' ' << *it;
      std::cout << std::endl;  
    
    //largerThan
    FMatrix m = rand(2,2);
    std::cout << "m =\n" << m << std::endl;
    std::cout<<" m > 0.5 \n" << (m > 0.5) <<std::endl;
    std::cout<<" 0.5 > m \n" << (0.5 > m) <<std::endl;
    
    //bitWiseMul
    std::cout << "m .* (m > 0.5) =\n" << bitWiseMul(m,(m > 0.5)) << std::endl; 
    
    //addPreColumn
    std::cout << "addPreColumn = \n" << addPreColumn(m,1) << std::endl;
    
    //delPreColumn
    std::cout << "delPreColumn = \n" << delPreColumn(addPreColumn(m,1)) << std::endl;
    
    //matrix mul
    FMatrix m1(2,3,1.0);
    std::cout << "m1 = \n" << m1 << std::endl;
    std::cout << "m * m1 = \n" << m * m1 << std::endl;
    std::cout << "m * 2 = \n" << m * 2 << std::endl;
    std::cout << "mul(m,2) = \n" << mul(m,2) << std::endl;
    
    //matrix trans
    std::cout << "trans(m) = \n" << trans(m) << std::endl;
    std::cout << "trans(m1) * m = \n" << trans(m1) * m << std::endl;
    
    
    //matrix sub
    FMatrix m2(2,2,2);
    std::cout << "m2 = \n" << m2 << std::endl;
    std::cout << "m = \n" << m << std::endl;
    std::cout << "m2 - m = \n" << m2 - m << std::endl;
    std::cout << "m2 - 1 = \n" << m2 - 1 << std::endl;
    std::cout << "1 - m2 = \n" << 1 - m2 << std::endl;
    std::cout << "- m2 = \n" << - m2 << std::endl;
    
    //matrix add
    std::cout << "m2 + m = \n" << m2 + m << std::endl;
    
    //matrix div
    std::cout << "m2 / 2 = \n" << m2 / 2 << std::endl;
//     std::cout << "2 / m2 = \n" << 2 / m2 << std::endl;
    
    
    //columnMean
    std::cout << "mean(m,1) = \n" << columnMean(m) << std::endl;
    
    //rowMaxIndexes
    std::cout << "max(m,[],2) = \n" << rowMaxIndexes(m) << std::endl;
    
    //matrixSum
    std::cout << "sum(m) = " << matrixSum(m) << std::endl;
    
    //bitWiseSquare
    std::cout << "m .^2 = \n" << bitWiseSquare(m) << std::endl;
    
    //bitWiseLog
    std::cout << "log(m) = \n" << bitWiseLog(m) << std::endl;
    
    //repmat
    std::cout << "repmat(m,2,3) = \n" << repmat(m,2,3) << std::endl;
    
    
    //findUnequalIndexes
    FColumn c(5UL,1);
    FColumn c1(5UL,1);
    std::cout << "c = \n" << c << std::endl;
    std::cout << "c1 = \n" << c1 << std::endl;
    std::vector<int> unequal_vec = findUnequalIndexes(c,c1);
    std::cout << "findUnequalIndexes = ";
    for(std::vector<int>::iterator it = unequal_vec.begin(); it != unequal_vec.end(); ++it)
      std::cout << *it << "\t";
    std::cout << std::endl;    
    c1[0] = 2;
    c1[2] = 5;
    c1[3] = 3;
    std::cout << "c1 = \n" << c1 << std::endl;
    unequal_vec = findUnequalIndexes(c,c1);
    std::cout << "findUnequalIndexes = ";
    for(std::vector<int>::iterator it = unequal_vec.begin(); it != unequal_vec.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}