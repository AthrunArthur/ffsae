#ifndef FFSAE_UTILS_MATLIB_H_
#define FFSAE_UTILS_MATLIB_H_

//This file is used to extend some operations from matlab
#include <cstdlib>
#include "dtype/type.h"

#include "common/common.h"
namespace ff
{


    double        rand(){
      return 1.0 * ::rand() / RAND_MAX ;
    }

    FMatrix      rand(int m, int n)
    {
        FMatrix res(m, n);
        for(int i = 0; i < m; i++)
          for(int j = 0; j < n; j++)
          {
            res(i, j) = rand();
          }
        return res;
    }

    template<class T1, class T2>
    struct is_one_matrix_one_arith{
        static const bool value = (std::is_arithmetic<T1>::value || std::is_arithmetic<T2>::value) && (is_matrix<T2>::value || is_matrix<T2>::value);
    };//end struct is_one_matrix_one_arith;

    template <class T1, class T2>
      struct matrix_type{
        typedef std::conditional<is_matrix<T1>::value, T1, T2>::type type;
      };//end struct matrix_type
    
    template<class T>
    FMatrix add(const FMatrix & m, T && v)
    {
        FMatrix res(m.rows(), m.columns());
        for(int i = 0; i < m.rows(); i++)
        {
           for(int j = 0; j < m.columns(); ++j)
           {
             res(i, j) = m(i, j) + v;
           }
        }
        return res;
    }
   
    template <class T1, class T2>
    typename matrix_type<T1, T2>::type operator + (T1 && t1, T2 && t2, 
        typename std::enable_if<
                is_one_matrix_one_arith<T1, T2>::value, 
                void>::type * p = nullptr)
    {
      if (is_matrix<T1>::value)
      {
        return add(t1, t2);
      }
      else
      {
        return add(t2, t1);
      }
    }

};//end namespace ff

#endif

