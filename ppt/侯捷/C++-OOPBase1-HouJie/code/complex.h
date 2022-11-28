#ifndef __MYCOMPLEX__		//防卫式声明 
#define __MYCOMPLEX__
							
class complex; 				//基本运算声明 
complex&
  __doapl (complex* ths, const complex& r);
complex&
  __doami (complex* ths, const complex& r);
complex&
  __doaml (complex* ths, const complex& r);


class complex				//类的具体内容 
{
public:
  complex (double r = 0, double i = 0): re (r), im (i) { }
  complex& operator += (const complex&);
  complex& operator -= (const complex&);
  complex& operator *= (const complex&);
  complex& operator /= (const complex&);
  double real () const { return re; }	//常成员函数(防止外界通过该函数改变私有的数据成员) 
  double imag () const { return im; }
private:
  double re, im;

  friend complex& __doapl (complex *, const complex&);	//友元函数(赋予友元函数操作私有数据成员的权力) 
  friend complex& __doami (complex *, const complex&);
  friend complex& __doaml (complex *, const complex&);
};

//基本运算加的实现 
inline complex&
__doapl (complex* ths, const complex& r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}
//重载运算符 += 
inline complex&
complex::operator += (const complex& r)
{
  return __doapl (this, r);
}
//基本运算减的实现 
inline complex&
__doami (complex* ths, const complex& r)
{
  ths->re -= r.re;
  ths->im -= r.im;
  return *ths;
}
//重载运算符 -= 
inline complex&
complex::operator -= (const complex& r)
{
  return __doami (this, r);
}
//基本运算乘的实现 
inline complex&
__doaml (complex* ths, const complex& r)
{
  double f = ths->re * r.re - ths->im * r.im;
  ths->im = ths->re * r.im + ths->im * r.re;
  ths->re = f;
  return *ths;
}
//重载运算符 *= 
inline complex&
complex::operator *= (const complex& r)
{
  return __doaml (this, r);
}
//返回imag 
inline double
imag (const complex& x)
{
  return x.imag ();
}
//返回real 
inline double
real (const complex& x)
{
  return x.real ();
}
//重载运算符 + _1 
inline complex
operator + (const complex& x, const complex& y)
{
  return complex (real (x) + real (y), imag (x) + imag (y));
}
//重载运算符 + _2 
inline complex
operator + (const complex& x, double y)
{
  return complex (real (x) + y, imag (x));
}
//重载运算符 + _3
inline complex
operator + (double x, const complex& y)
{
  return complex (x + real (y), imag (y));
}
//重载运算符 - _1
inline complex
operator - (const complex& x, const complex& y)
{
  return complex (real (x) - real (y), imag (x) - imag (y));
}
//重载运算符 - _2 
inline complex
operator - (const complex& x, double y)
{
  return complex (real (x) - y, imag (x));
}
//重载运算符 - _3 
inline complex
operator - (double x, const complex& y)
{
  return complex (x - real (y), - imag (y));
}
//重载运算符 * _1 
inline complex
operator * (const complex& x, const complex& y)
{
  return complex (real (x) * real (y) - imag (x) * imag (y),
			   real (x) * imag (y) + imag (x) * real (y));
}
//重载运算符 * _2 
inline complex
operator * (const complex& x, double y)
{
  return complex (real (x) * y, imag (x) * y);
}
//重载运算符 * _3 
inline complex
operator * (double x, const complex& y)
{
  return complex (x * real (y), x * imag (y));
}
//重载运算符 / 
complex
operator / (const complex& x, double y)
{
  return complex (real (x) / y, imag (x) / y);
}
//重载运算符 + _取正 
inline complex
operator + (const complex& x)
{
  return x;
}
//重载运算符 - _取反 
inline complex
operator - (const complex& x)
{
  return complex (-real (x), -imag (x));
}
//重载运算符 == _1 
inline bool
operator == (const complex& x, const complex& y)
{
  return real (x) == real (y) && imag (x) == imag (y);
}
//重载运算符 == _2 
inline bool
operator == (const complex& x, double y)
{
  return real (x) == y && imag (x) == 0;
}
//重载运算符 == _3 
inline bool
operator == (double x, const complex& y)
{
  return x == real (y) && imag (y) == 0;
}
//重载运算符 != _1 
inline bool
operator != (const complex& x, const complex& y)
{
  return real (x) != real (y) || imag (x) != imag (y);
}
//重载运算符 != _2 
inline bool
operator != (const complex& x, double y)
{
  return real (x) != y || imag (x) != 0;
}
//重载运算符  !=_3
inline bool
operator != (double x, const complex& y)
{
  return x != real (y) || imag (y) != 0;
}

#include <cmath>

inline complex
polar (double r, double t)
{
  return complex (r * cos (t), r * sin (t));
}
//共轭复数 
inline complex
conj (const complex& x) 
{
  return complex (real (x), -imag (x));
}
//
inline double
norm (const complex& x)
{
  return real (x) * real (x) + imag (x) * imag (x);
}

#endif   //__MYCOMPLEX__




