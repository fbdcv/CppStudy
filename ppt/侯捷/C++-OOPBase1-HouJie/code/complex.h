#ifndef __MYCOMPLEX__		//����ʽ���� 
#define __MYCOMPLEX__
							
class complex; 				//������������ 
complex&
  __doapl (complex* ths, const complex& r);
complex&
  __doami (complex* ths, const complex& r);
complex&
  __doaml (complex* ths, const complex& r);


class complex				//��ľ������� 
{
public:
  complex (double r = 0, double i = 0): re (r), im (i) { }
  complex& operator += (const complex&);
  complex& operator -= (const complex&);
  complex& operator *= (const complex&);
  complex& operator /= (const complex&);
  double real () const { return re; }	//����Ա����(��ֹ���ͨ���ú����ı�˽�е����ݳ�Ա) 
  double imag () const { return im; }
private:
  double re, im;

  friend complex& __doapl (complex *, const complex&);	//��Ԫ����(������Ԫ��������˽�����ݳ�Ա��Ȩ��) 
  friend complex& __doami (complex *, const complex&);
  friend complex& __doaml (complex *, const complex&);
};

//��������ӵ�ʵ�� 
inline complex&
__doapl (complex* ths, const complex& r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}
//��������� += 
inline complex&
complex::operator += (const complex& r)
{
  return __doapl (this, r);
}
//�����������ʵ�� 
inline complex&
__doami (complex* ths, const complex& r)
{
  ths->re -= r.re;
  ths->im -= r.im;
  return *ths;
}
//��������� -= 
inline complex&
complex::operator -= (const complex& r)
{
  return __doami (this, r);
}
//��������˵�ʵ�� 
inline complex&
__doaml (complex* ths, const complex& r)
{
  double f = ths->re * r.re - ths->im * r.im;
  ths->im = ths->re * r.im + ths->im * r.re;
  ths->re = f;
  return *ths;
}
//��������� *= 
inline complex&
complex::operator *= (const complex& r)
{
  return __doaml (this, r);
}
//����imag 
inline double
imag (const complex& x)
{
  return x.imag ();
}
//����real 
inline double
real (const complex& x)
{
  return x.real ();
}
//��������� + _1 
inline complex
operator + (const complex& x, const complex& y)
{
  return complex (real (x) + real (y), imag (x) + imag (y));
}
//��������� + _2 
inline complex
operator + (const complex& x, double y)
{
  return complex (real (x) + y, imag (x));
}
//��������� + _3
inline complex
operator + (double x, const complex& y)
{
  return complex (x + real (y), imag (y));
}
//��������� - _1
inline complex
operator - (const complex& x, const complex& y)
{
  return complex (real (x) - real (y), imag (x) - imag (y));
}
//��������� - _2 
inline complex
operator - (const complex& x, double y)
{
  return complex (real (x) - y, imag (x));
}
//��������� - _3 
inline complex
operator - (double x, const complex& y)
{
  return complex (x - real (y), - imag (y));
}
//��������� * _1 
inline complex
operator * (const complex& x, const complex& y)
{
  return complex (real (x) * real (y) - imag (x) * imag (y),
			   real (x) * imag (y) + imag (x) * real (y));
}
//��������� * _2 
inline complex
operator * (const complex& x, double y)
{
  return complex (real (x) * y, imag (x) * y);
}
//��������� * _3 
inline complex
operator * (double x, const complex& y)
{
  return complex (x * real (y), x * imag (y));
}
//��������� / 
complex
operator / (const complex& x, double y)
{
  return complex (real (x) / y, imag (x) / y);
}
//��������� + _ȡ�� 
inline complex
operator + (const complex& x)
{
  return x;
}
//��������� - _ȡ�� 
inline complex
operator - (const complex& x)
{
  return complex (-real (x), -imag (x));
}
//��������� == _1 
inline bool
operator == (const complex& x, const complex& y)
{
  return real (x) == real (y) && imag (x) == imag (y);
}
//��������� == _2 
inline bool
operator == (const complex& x, double y)
{
  return real (x) == y && imag (x) == 0;
}
//��������� == _3 
inline bool
operator == (double x, const complex& y)
{
  return x == real (y) && imag (y) == 0;
}
//��������� != _1 
inline bool
operator != (const complex& x, const complex& y)
{
  return real (x) != real (y) || imag (x) != imag (y);
}
//��������� != _2 
inline bool
operator != (const complex& x, double y)
{
  return real (x) != y || imag (x) != 0;
}
//���������  !=_3
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
//����� 
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




