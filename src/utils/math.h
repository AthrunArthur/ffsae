/*
 * This shall be header file for mathmatic
 */
#ifndef FFSAE_UTILS_MATH_H_
#define FFSAE_UTILS_MATH_H_

#include <cmath>
#include <cstdlib>
#include <time.h>

namespace ff{
    double        sigm(const double & x){return 1.0/(1+exp(-x));};//原函数直接实现矩阵计算
    
    double        sigmrnd(const double & x){//原sigmrnd.m中是对矩阵直接计算并返回矩阵结果，并用matlab的rand函数生成0-1间数的随机矩阵并进行比较
        srand(time(NULL));
        return double(1.0/(1+exp(-x)) > double(rand())/RAND_MAX);
    };//仅在DBN/rbmtrain.m中用到，SAE中未使用
    
    void        softmax(double * x, int n_out){
        //原函数对矩阵进行计算，这里直接对一维数组计算,n_out表示数组长度，要求用户输入数组长度必须正确。结果直接修改原数组内容
        double sum = 0.0;
        //     double max = 0.0;//注释掉的是可以优化softmax效果的代码，官方代码中未提供
        //     for(int i=0; i<n_out; i++) if(max < x[i]) max = x[i];
        for(int i=0; i<n_out; i++) {
            // x[i] = exp(x[i] - max);
            x[i] = exp(x[i] * 3);//参照softmax.m，c=3，直接取值3未保留c变量。
            sum += x[i];
        }
        for(int i=0; i<n_out; i++) x[i] /= sum;
    };//SAE示例代码中未使用
    
    double        tanh_opt(const double & x){return 1.7159*tanh(2.0/3 * x);};//原函数直接实现矩阵计算
}//end namespace ff
#endif
