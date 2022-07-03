/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:20:06
 */
#include <iostream>
using namespace std;
int main() {
  double x = 123.456;
  cout.width(10);
  cout.setf(ios::dec, ios::basefield);
  cout << x << endl;
  cout.setf(ios::left);
  cout << x << endl;
  cout.width(15);
  cout.setf(ios::right, ios::left);
  cout << x << endl;
  cout.setf(ios::showpos);
  cout << x << endl;
  cout << -x << endl;
  cout.setf(ios::scientific);
  cout << x << endl;
}