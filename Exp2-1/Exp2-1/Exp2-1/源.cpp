#include<iostream>
using namespace std;
class complex{ 
public:complex(double r, double i): r(r), i(i){cout<<"Constructor!"<<*this ; }
	  complex(double r): r(r), i(0){cout<<"Cast Constructor!"<< *this;}
	  complex(const complex &c): r(c.r), i(c.i){cout<<"Copy Constructor!"<< *this;}
	  //operator double()//类型转换函数
	  //{cout<<"Cast Double!"<<r<<endl; return r;}
	  ~complex(){cout<<"Destructor!"<< *this;}//析构函数
	  friend complex operator+(const complex &, const complex &); //重载运算符+为成员函数
	  friend ostream &operator<<(ostream &, const complex& );   //重载输出函数
private:double r, i;
	   //复数实部、虚部
};
complex operator+(const complex& c1, const complex& c2) //成员函数有一个参量
{ return complex(c1.r+c2.r, c1.i+c2.i); }
ostream &operator<<(ostream &output, const complex& c) //重载输出函数
{ output<<"("<<c.r<<","<<c.i<<")"<<endl;  return output; }
int main(){ 
	//main函数，程序的主体
	complex c1(5,4), c2(2,10);//声明复数类对象
	cout <<c1+c2;
	cout << c1 << c2 ;
	return 0;
}
//#include <iostream>
//
//using namespace std;
//
//class Complex
//
//{
//public:
//
//    Complex() { real = 0; imag = 0; }    //默认构造函数
//
//    Complex(double r) { real = r; imag = 0; } //转换构造函数
//
//    Complex(double r, double i) { real = r; imag = i; }//实现初始化的构造函数
//
//    friend Complex operator + (Complex c1, Complex c2); //重载运算符      
//                                                      //"+"的友元函数
//
//    void display();
//
//private:
//
//    double real;
//
//    double imag;
//
//};
//
//Complex operator + (Complex c1, Complex c2)//定义运算符"+"重 
//                                                            //载函数
//
//{
//    return Complex(c1.real + c2.real, c1.imag + c2.imag);
//}
//
//void Complex::display()
//
//{
//    cout << "( "<< real << ", " << imag << "i" << endl;
//}
//
//int main()
//
//{
//    Complex c1(3, 4), c2(5, -10), c3;
//
//    c3 = c1 + 2.5;          //复数与double数据相加
//
//    c3.display();
//
//    return 0;
//
//}
