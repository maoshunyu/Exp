/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:19:59
 */
#include <iostream>
using namespace std;
class MyClass {
public:
  MyClass() {
    data = new int[11];
    for (int i = 0; i < 11; i++) data[i] = i;
  }

  ~MyClass() {}
  int* data;

private:
};
int main() {
  int* addr;
  {
    MyClass test;
    addr = test.data;
    for (int i = 0; i < 11; i++) cout << *(addr + i);
    cout << endl;
  }
  for (int i = 0; i < 11; i++) cout << *(addr + i);
  cout << endl;
}
