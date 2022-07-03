/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:18:42
 */
#include <iostream>
using namespace std;

class ArrayOperation {
public:
  ArrayOperation() : m_Array(new int[10]) {}
  ArrayOperation(const ArrayOperation& rhs) : m_Array(new int[10]) {
    memcpy(m_Array.get(), rhs.m_Array.get(), 10 * sizeof(int));
  }
  void InitArray() {
    for (int i = 0; i < 10; ++i) { m_Array[i] = i; }
  }

  void ShowArray() {
    for (int i = 0; i < 10; ++i) { cout << m_Array[i] << endl; }
  }

  ~ArrayOperation() { cout << "~ArrayOperation is called" << endl; }

private:
  unique_ptr<int[]> m_Array;
};
ArrayOperation test() {
  ArrayOperation op;
  return op;
}
int main() {
  ArrayOperation op;
  ArrayOperation a;
  // a = test();

  return 0;
}