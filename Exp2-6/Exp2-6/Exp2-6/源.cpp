#include <iostream>
using namespace std;
class Base {
public:
	Base(int i) :b_number(i) {
	}
	~Base() {
	}
	int get_number() { return b_number; }
	void print() { cout << b_number << endl; }
private:
	int b_number;
};
class Derived :protected Base{
public:
	Derived(int i,int j) :Base(i),d_number(j) {
	}

	~Derived() {
	}
	void print() {
		cout << get_number() << " " << d_number << endl;
	}
private:
	int d_number;
};

int main() {
	Base a(2);
	Derived b(3, 4);
	cout << "a is ";
	a.print();
	cout << "b is ";
	b.print();
	cout << "base part of b is ";
	b.Base::print();
}