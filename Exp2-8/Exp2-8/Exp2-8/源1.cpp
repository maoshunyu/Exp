/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:20:27
 */
#include <iostream>
using namespace std;
class Shape {
public:
  Shape() {}
  ~Shape() {}
  virtual float GetPerim() = 0;
  virtual float GetArea() = 0;

private:
};
class Circle : public Shape {
public:
  Circle(float radius) : r(radius) {}

  ~Circle() {}
  virtual float GetPerim() { return 2 * 3.14159 * r; }
  virtual float GetArea() { return 3.14159 * r * r; }

private:
  float r;
};
class Rectangle : public Shape {
public:
  Rectangle(float length) : len(length) {}

  ~Rectangle() {}
  virtual float GetPerim() { return 4 * len; }
  virtual float GetArea() { return len * len; }

private:
  float len;
};

int main() {
  Circle cir(3.0);
  Rectangle in(2.0 * 3.0 / 1.414), out(2 * 3.0);
  cout << "�ܳ���" << cir.GetPerim() << "  "
       << "�����" << cir.GetArea() << endl;
  cout << "�ܳ���" << in.GetPerim() << "  "
       << "�����" << in.GetArea() << endl;
  cout << "�ܳ���" << out.GetPerim() << "  "
       << "�����" << out.GetArea() << endl;
}
