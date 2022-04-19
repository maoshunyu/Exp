# 第四次作业

## 第一题

#### 可以声明在private，无this指针。

## 第二题

```cpp
#include <iostream>
using namespace std;
class People {
public:

	class Date {
	public:
		Date(int y,int m,int d):year(y),month(m),day(d) {
		}

		~Date() {
		}
		int year, month, day;
		friend ostream& operator <<(ostream& o, Date& d);
	private:

	};
	
	char name[11];
	char number[7];
	char sex[3];
	char id[16];
	Date birthday;
	People(const char name[11], const char number[7], const char sex[3],const char id[16],int y,int m,int d):birthday(y,m,d) {
		strcpy_s(this->name, 11,name);
		strcpy_s(this->number, 7,number);
		strcpy_s(this->sex, 3,sex);
		strcpy_s(this->id, 16,id);
	}

	~People() {
	}
	People(const People& r) :birthday(r.birthday) {
		strcpy_s(this->name, 11,r.name);
		strcpy_s(this->number,7, r.number);
		strcpy_s(this->sex,3, r.sex);
		strcpy_s(this->id,16, r.id);
	}
	inline void show() {
		cout << "name: " << name << "  " << "number: " << number << "  " << "sex: " << sex << "  " << "id:  " << id << "  " << "birthday:  "<<birthday;
	}
private:

};

int main()
{
	People p("alice", "1", "wo", "12345678",2003, 1, 1);
	People p1(p);
	p1.show();
}

ostream& operator<<(ostream& o, People::Date& d) {
	o << d.year << "年 " << d.month << "月 " << d.day << "日 ";
	return o;
}

```

![image-20220310103734990](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220310103734990.png)

-------

## 第三题

```cpp
#include <iostream>
#include <iomanip>
using namespace std;
class Matrix {
public:
	Matrix(int rol,int col,int**& array) {
		init(rol,col);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = array[i][j];
			}
		}

	}
	Matrix(int rol,int col){
		init(rol, col);
	}
	Matrix(int rol, int col,int val) {
		init(rol, col);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = val;
			}
		}
	}
	~Matrix() {
	}
	inline void init(int rol,int col){
		m = rol, n = col;
		a = new int* [m];
		for (int i = 0; i < m; i++) {
			a[i] = new int[n];
		}
	}
	inline void set(int x, int y,int val) {
		a[x][y] = val;
	}
	inline int get(int x, int y) {
		return a[x][y];
	}
	inline void show() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << setw(3) <<setiosflags(ios::left) << a[i][j];
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	friend Matrix operator+(Matrix& a, Matrix& b);
	friend Matrix operator-(Matrix& a, Matrix& b);
private:
	int** a;
	int m,n;
};


int main() {
	int size;
	cout << "input the size:";
	cin >> size;

	int** a =new int*[size];
	for (int i = 0; i < size; i++) {
		a[i] = new int[size];
		for (int j = 0; j < size; j++) {
			a[i][j] = i + j;
		}
	}
    Matrix ma(size,size,a);
    
	int** b = new int* [size];
	for (int i = 0; i < size; i++) {
		b[i] = new int[size];
		for (int j = 0; j < size; j++) {
			cin >> b[i][j];
		}
	}
	Matrix mb(size, size, b);
    
	ma.show();
	mb.show();
	cout << "+" << endl;
	(ma + mb).show();
	cout << "-" << endl;
	(ma - mb).show();
}
Matrix operator-(Matrix& a, Matrix& b) {
	int rol = a.m, col = a.n;
	Matrix m(rol, col);
	for (int i = 0; i < rol; i++) {
		for (int j = 0; j < col; j++) {
			m.set(i, j, (a.get(i, j) - b.get(i, j)));
		}
	}
	return m;
}
Matrix operator+(Matrix& a, Matrix& b) {
	int rol = a.m, col = a.n;
	Matrix m(rol, col);
	for (int i = 0; i < rol; i++) {
		for (int j = 0; j < col; j++) {
			m.set(i, j, (a.get(i, j) + b.get(i, j)));
		}
	}
	return m;
}

```

![image-20220310113333238](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220310113333238.png)