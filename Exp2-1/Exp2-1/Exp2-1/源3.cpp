/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-03-24 16:50:53
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:20:01
 */
#include <iostream>
// #include "???.h"
using namespace std;

int main() {
  // double a[6] = { 1,2,3,4,5,6 }, b[6] = { 1,4,2,5,3,6 };

  // double a[6];

  // shared_ptr<double[]> ptra(new double[6]);
  // shared_ptr<double[]> ptrb(new double[6]);
  // for (int i = 0; i < 6; i++)
  // 	ptra[i] = (double)i + 1;
  // for (int i = 0; i < 6; i++) {
  // 	ptrb[i] = i + 1;
  // }
  // Matrix A(ptra, 2, 3), B(ptrb, 3, 2);
  // A.Matshow();
  // B.Matshow();
  // //Matrix m(pdate, 3, 3);

  // Matrix C;//new double;  A*B -> copy -> assign
  // C = A * B;

  // Matrix D = A * B;//A*B ->copy->assign

  // D.Matshow();
  // C.Matshow();

  // //(A * B).Matshow();
  // return 0;
}
class Shape {
public:
  Shape() {}

  ~Shape() {}
  virtual double getC() = 0;
  virtual double getS() = 0;

private:
};
class Circle : public Shape {
private:
  /* data */
public:
  Circle(/* args */) {}
  ~Circle() {}
};
class p3 : public Shape {
private:
  /* data */
public:
  p3(/* args */) {}
  ~p3() {}
};