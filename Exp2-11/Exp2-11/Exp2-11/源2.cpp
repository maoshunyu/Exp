#include <iostream>
using namespace std;

class A {

public:

	A(int m) :mem(m) {
		cout << "Construct:" << this << endl;
	}
	A(const A& a) :mem(a.mem) {
		cout << "Copy Construct:" << this << endl;
	}
	~A() {
		cout << "Destrcut:" << this << endl;
	}
private:

	int mem;

			};

			A fun() {

				return A(10);

			}

int main() {

	A a(12);

	A b(fun());

	cout << &b << endl;

}

