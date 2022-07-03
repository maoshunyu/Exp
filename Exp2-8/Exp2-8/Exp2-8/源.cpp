/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:17:32
 */
#include <iostream>
using namespace std;
class Shape {
public:
  Shape() {}
  virtual ~Shape() {}
  virtual double getC() = 0;
  virtual double getS() = 0;

private:
};
class Circle : public Shape {
public:
  Circle(double radius) : r(radius) {}

  ~Circle() {}
  virtual double getC() { return 2 * 3.14159 * r; }
  virtual double getS() { return 3.14159 * r * r; }

private:
  double r;
};
class Rectangle : public Shape {
public:
  Rectangle(double length) : len(length) {}

  ~Rectangle() {}
  virtual double getC() { return 4 * len; }
  virtual double getS() { return len * len; }

private:
  double len;
};
double getPerim(Shape& s) { return s.getC(); }
double getArea(Shape& s) { return s.getS(); }
int main() {
  Circle cir(3.0);
  Rectangle in(2.0 * 3.0 / 1.414), out(2 * 3.0);
  cout << "�ܳ���" << getPerim(cir) << "  "
       << "�����" << getArea(cir) << endl;
  cout << "�ܳ���" << in.getC() << "  "
       << "�����" << in.getS() << endl;
  cout << "�ܳ���" << out.getC() << "  "
       << "�����" << out.getS() << endl;
}