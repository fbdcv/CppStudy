#ifndef __MYSTRING__ //防卫式声明 
#define __MYSTRING__

class String
{
public:                                 
   String(const char* cstr=0);					//构造函数                   
   String(const String& str);               	//拷贝构造函数     
   String& operator=(const String& str);        //拷贝赋值函数 
   ~String();                                   //析构函数 
   char* get_c_str() const { return m_data; }
private:
   char* m_data;
};

#include <cstring>

inline
String::String(const char* cstr)
{
   if (cstr) {
      m_data = new char[strlen(cstr)+1];	//开辟内存空间 
      strcpy(m_data, cstr);					 
   }
   else {   
      m_data = new char[1];
      *m_data = '\0';
   }
}

inline
String::~String()
{
   delete[] m_data;							//array new 要搭配 array delete,防止只释放array首地址所指向的元素空间 
}

inline
String& String::operator=(const String& str)
{
   if (this == &str)						//检测自我赋值,防止拷贝失败并造成内存泄露 
      return *this;

   delete[] m_data;
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
   return *this;
}

inline
String::String(const String& str)			
{
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
}

#include <iostream>
using namespace std;
//重载运算符 << 
ostream& operator<<(ostream& os, const String& str)
{
   os << str.get_c_str();
   return os;
}

#endif
