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
class Circle :public Shape {
public:
	Circle(float radius) :r(radius) {}

	~Circle() {}
	virtual float GetPerim() {
		return 2 * 3.14159 * r;
	}
	virtual float GetArea() {
		return 3.14159 * r * r;
	}
private:
	float r;
};
class Rectangle :public Shape {
public:
	Rectangle(float length) :len(length) {}

	~Rectangle() {}
	virtual float GetPerim() {
		return 4 * len;
	}
	virtual float GetArea() {
		return len * len;
	}
private:
	float len;
};

int main() {
	Circle cir(3.0);
	Rectangle in(2.0 * 3.0 / 1.414), out(2 * 3.0);
	cout << "周长：" << cir.GetPerim() << "  " << "面积：" << cir.GetArea() << endl;
	cout << "周长：" << in.GetPerim() << "  " << "面积：" << in.GetArea() << endl;
	cout << "周长：" << out.GetPerim() << "  " << "面积：" << out.GetArea() << endl;

}

