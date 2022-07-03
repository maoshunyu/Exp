/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-12 16:09:46
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:21:28
 */
#include <iostream>
using namespace std;

class A {
public:
  A(int m) : mem(m) { cout << "Construct:" << this << endl; }
  A(const A& a) : mem(a.mem) { cout << "Copy Construct:" << this << endl; }
  ~A() { cout << "Destrcut:" << this << endl; }

private:
  int mem;
};

A fun() { return A(10); }

int main() {
  A a(12);

  A b(fun());

  cout << &b << endl;
}
