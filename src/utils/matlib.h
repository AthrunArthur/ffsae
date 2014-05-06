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

    template<class T>
    size_t      numel(const T & t, typename std::enable_if<is_matrix<T>::value, void>::type *p = nullptr)
    {
      return t.rows() * t.columns();
    }

    FMatrix  zeros(int m, int n)
    {
      FMatrix res(m, n, 0.0);
      return res;
    }
    ///TODO : performance issue here, we should use lazy evaluation here!
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
   
    template<class T>
    FMatrix sub(const FMatrix & m, T && v)
    {
        FMatrix res(m.rows(), m.columns());
        for(int i = 0; i < m.rows(); i++)
        {
           for(int j = 0; j < m.columns(); ++j)
           {
             res(i, j) = m(i, j) - v;
           }
        }
        return res;
    }

    template<class T>
    FMatrix mul(const FMatrix & m, T && v)
    {
        FMatrix res(m.rows(), m.columns());
        for(int i = 0; i < m.rows(); i++)
        {
           for(int j = 0; j < m.columns(); ++j)
           {
             res(i, j) = m(i, j) * v;
           }
        }
        return res;
    }
    template<class T>
    FMatrix div(const FMatrix & m, T && v)
    {
        FMatrix res(m.rows(), m.columns());
        for(int i = 0; i < m.rows(); i++)
        {
           for(int j = 0; j < m.columns(); ++j)
           {
             res(i, j) = m(i, j) / v;
           }
        }
        return res;
    }
};//end namespace ff
    template <class T>
    ff::FMatrix operator + (const ff::FMatrix & t1, const T & t )
    {
      return ff::add(t1, t);
    }
    template <class T>
    ff::FMatrix operator + (const T & t1, const ff::FMatrix & t )
    {
      return ff::add(t, t1);
    }
   //////////////////////////////
    template <class T>
    ff::FMatrix operator-  (const ff::FMatrix & t1, const T & t )
    {
      return ff::sub(t1, t);
    }
    template <class T>
    ff::FMatrix operator - (const T & t1, const ff::FMatrix & t )
    {
      return ff::sub(t, t1);
    }
/////////////////
    template <class T>
    ff::FMatrix operator * (const ff::FMatrix & t1, const T & t )
    {
      return ff::mul(t1, t);
    }
    template <class T>
    ff::FMatrix operator * (const T & t1, const ff::FMatrix & t )
    {
      return ff::mul(t, t1);
    }
////////////////
    template <class T>
    ff::FMatrix operator / (const ff::FMatrix & t1, const T & t )
    {
      return ff::div(t1, t);
    }
    template <class T>
    ff::FMatrix operator / (const T & t1, const ff::FMatrix & t )
    {
      return ff::div(t, t1);
    }
#endif

