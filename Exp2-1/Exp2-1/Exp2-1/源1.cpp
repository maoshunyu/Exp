/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:18:51
 */
#include <iostream>
using namespace std;

class P {
public:
  P(string&& name) : _name(name) {}
  P(const P& p) {
    _name = p._name;
    cout << "copied" << endl;
  }
  ~P() {}
  string _name;

private:
};
void swap(P& a, P& b) {
  P tmp(move(a));
  a = b;
  b = move(tmp);
}

int main() {
  string s = "aa";
  P a(move(s));

  P b("bb");
  /*swap(a, b);*/
  cout << "a:" << a._name << endl;
  cout << "b:" << b._name << endl;
}