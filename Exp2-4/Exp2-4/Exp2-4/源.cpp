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


