/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:18:40
 */
#include <fstream>
#include <iostream>
using namespace std;
int main() {
  ifstream f("essay.txt");
  char* file = new char[31];
  int num = 0;
  while (f.good()) {
    f.getline(file, 30);
    cout << file << endl;
    num++;
  }
  cout << "������ " << num;
}