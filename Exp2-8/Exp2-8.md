# 第八次作业

# 第一题

f1不是虚函数，执行结果应该是B::f1;B::f1

-------------

## 第二题

```cpp
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
class Rect :public Shape{
public:
	Rect(double length):len(length) {}

	~Rect() {}
	virtual double getC() {
		return 4 * len;
	}
	virtual double getS() {
		return len * len;
	}
private:
	double len;
};

int main() {
	Circle cir(3.0);
	Rect in(2.0 * 3.0 / 1.414), out(2 * 3.0);
	cout << "周长：" << cir.getC() << "  " << "面积：" << cir.getS() << endl;
	cout << "周长：" << in.getC() << "  " << "面积：" << in.getS() << endl;
	cout << "周长：" << out.getC() << "  " << "面积：" << out.getS() << endl;
}
```

![image-20220419141700521](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220419141700521.png)

------------

## 第三题

```cpp
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
```

![image-20220419142001234](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220419142001234.png)