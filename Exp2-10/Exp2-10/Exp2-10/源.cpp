/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 23:28:06
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:18:44
 */
#include <iostream>
using namespace std;
template <typename T>
void sort(T a[], const int n, const bool reversed) {
  int is_r = reversed ? 1 : -1;
  for (int i = 0; i < n; i++) {
    int min_in = i;
    for (int j = i; j < n; j++) {
      if (is_r * (a[j] - a[min_in]) > 0) min_in = j;
    }
    T temp = a[i];
    a[i] = a[min_in];
    a[min_in] = temp;
  }
}

int main() {
  int a[] = {3, 654, 76, 2, 6, 98, 67, 2, 543, 2};
  char c[] = "hfasudifhsdahfi";
  const string str = "fhausdhfaskdfas";
  const auto p = new char[str.length() + 1];
  strcpy_s(p, str.length() + 1, str.c_str());

  sort(a, sizeof(a) / sizeof(int), false);
  sort(c, sizeof(c) / sizeof(char), true);
  sort(p, str.length(), false);
  cout << c << endl << p << endl;
  for (const int i : a) { cout << i << "  "; }
}
