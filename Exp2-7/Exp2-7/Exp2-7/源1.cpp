/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:19:07
 */
#include <iostream>
using namespace std;
class B1 {
public:
  B1(int i) { cout << "B1:  " << i << endl; }
  ~B1() {}

private:
};
class B2 {
public:
  B2() { cout << "B2  " << endl; }

  ~B2() {}

private:
};
class C : public B2, virtual public B1 {
public:
  C(int a, int b) : B1(a), mb1(b), mb2(), pm2(new B2) {}

  ~C() {}

private:
  B2 mb2;
  B1 mb1;
  B2* pm2;
};
int main() { C a(1, 2); }