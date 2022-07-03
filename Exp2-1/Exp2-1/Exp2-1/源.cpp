/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:16:16
 */
#include <iostream>
using namespace std;
class complex {
public:
  complex(double r, double i) : r(r), i(i) { cout << "Constructor!" << *this; }
  complex(double r) : r(r), i(0) { cout << "Cast Constructor!" << *this; }
  complex(const complex &c) : r(c.r), i(c.i) {
    cout << "Copy Constructor!" << *this;
  }
  // operator double()//����ת������
  //{cout<<"Cast Double!"<<r<<endl; return r;}
  ~complex() { cout << "Destructor!" << *this; }  //��������
  friend complex operator+(const complex &,
                           const complex &);  //���������+Ϊ��Ա����
  friend ostream &operator<<(ostream &, const complex &);  //�����������
private:
  double r, i;
  //����ʵ�����鲿
};
complex operator+(const complex &c1, const complex &c2)  //��Ա������һ������
{
  return complex(c1.r + c2.r, c1.i + c2.i);
}
ostream &operator<<(ostream &output, const complex &c)  //�����������
{
  output << "(" << c.r << "," << c.i << ")" << endl;
  return output;
}
int main() {
  // main���������������
  complex c1(5, 4), c2(2, 10);  //�������������
  cout << c1 + c2;
  cout << c1 << c2;
  return 0;
}
//#include <iostream>
//
// using namespace std;
//
// class Complex
//
//{
// public:
//
//    Complex() { real = 0; imag = 0; }    //Ĭ�Ϲ��캯��
//
//    Complex(double r) { real = r; imag = 0; } //ת�����캯��
//
//    Complex(double r, double i) { real = r; imag = i; }//ʵ�ֳ�ʼ���Ĺ��캯��
//
//    friend Complex operator + (Complex c1, Complex c2); //���������
//                                                      //"+"����Ԫ����
//
//    void display();
//
// private:
//
//    double real;
//
//    double imag;
//
//};
//
// Complex operator + (Complex c1, Complex c2)//���������"+"��
//                                                            //�غ���
//
//{
//    return Complex(c1.real + c2.real, c1.imag + c2.imag);
//}
//
// void Complex::display()
//
//{
//    cout << "( "<< real << ", " << imag << "i" << endl;
//}
//
// int main()
//
//{
//    Complex c1(3, 4), c2(5, -10), c3;
//
//    c3 = c1 + 2.5;          //������double�������
//
//    c3.display();
//
//    return 0;
//
//}
