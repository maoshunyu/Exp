/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:18:04
 */
#include <iomanip>
#include <iostream>
using namespace std;
class Date {
public:
  Date(int dd = 0, int mm = 0, int yy = 0);
  Date(const Date& D);
  ~Date();

private:
  int d, m, y;
};

Date::Date(int dd, int mm, int yy) : d(dd), m(mm), y(yy) {
  cout << "Constructor Called. Address=0x" << hex << setw(8) << setfill('0')
       << this << endl;
}

Date::Date(const Date& D) {
  d = D.d;
  m = D.m;
  y = D.y;
  cout << "Copy Constructor Called. Address=0x" << hex << setw(8)
       << setfill('0') << this << endl;
}

Date::~Date() {
  cout << "Destructor Called. Address=0x" << hex << setw(8) << setfill('0')
       << this << endl;
}
Date& func(Date A) {
  Date B(A);
  return B;
}
int main() {
  Date today;
  today = func(today);

  return 0;
}