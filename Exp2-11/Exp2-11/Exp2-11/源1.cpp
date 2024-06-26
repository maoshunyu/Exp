/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-10 23:25:07
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:21:33
 */
#include <iostream>
#include <random>
#include <set>
using namespace std;
int main(int argc, char* argv[]) {
  set<int> a, b, c, d, e;

  random_device rd;
  const uniform_int_distribution<> dis(-10000, 10000);
  for (int i = 0; i < 10; ++i) { a.insert(dis(rd)); }
  for (int i = 0; i < 5; ++i) { b.insert(dis(rd)); }
  for (int i = 0; i < 15; ++i) { c.insert(dis(rd)); }
  set_intersection(a.begin(), a.end(), c.begin(), c.end(),
                   inserter(d, d.begin()));
  set_union(b.begin(), b.end(), d.begin(), d.end(), inserter(e, e.begin()));
  for (const int e1 : e) { cout << e1 << endl; }
}
