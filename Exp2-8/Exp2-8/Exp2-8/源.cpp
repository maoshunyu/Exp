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
class Circle :public Shape{
public:
	Circle(double radius):r(radius) {}

	~Circle() {}
	virtual double getC() {
		return 2 * 3.14159 * r;
	}
	virtual double getS() {
		return 3.14159 * r * r;
	}
private:
	double r;
};
class Rectangle :public Shape{
public:
	Rectangle(double length):len(length) {}

	~Rectangle() {}
	virtual double getC() {
		return 4 * len;
	}
	virtual double getS() {
		return len * len;
	}
private:
	double len;
};
double getPerim( Shape& s) {
	return s.getC();
}
double getArea( Shape& s) {
	return s.getS();
}
int main() {
	Circle cir(3.0);
	Rectangle in(2.0 * 3.0 / 1.414), out(2 * 3.0);
	cout << "周长：" << getPerim(cir) << "  " << "面积：" << getArea(cir) << endl;
	cout << "周长：" << in.getC() << "  " << "面积：" << in.getS() << endl;
	cout << "周长：" << out.getC() << "  " << "面积：" << out.getS() << endl;
}