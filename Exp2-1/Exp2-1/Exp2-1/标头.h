#pragma once
#include <assert.h>
using namespace std;
class Matrix {
public:
	Matrix();
	Matrix(shared_ptr<double[]>& pdate, int r, int c);
	Matrix(const Matrix& rhs):row(rhs.row),col(rhs.col),date(new double[100]) {
		memcpy(date.get(), rhs.date.get(), 100 * sizeof(double));
	}
	Matrix& operator=(const Matrix& rhs) {
		date.reset();
		date = make_shared<double[]>(100);
		memcpy(date.get(), rhs.date.get(), 100 * sizeof(double));
		row = rhs.row;
		col = rhs.col;
		return *this;
	}
	~Matrix();
	double& operator()(int r, int c);
	Matrix operator*(Matrix& m);
	
	void Matshow();
private:
	shared_ptr<double[]> date;
	int row;
	int col;
};

Matrix::Matrix():date(new double[100]) {

	row = 0;
	col = 0;
}

Matrix::Matrix(shared_ptr<double[]>& pDate, int r, int c) {

	date = pDate;
	//memcpy(date.get(), pDate.get(), sizeof(double) * r * c);

	row = r;
	col = c;
}

Matrix::~Matrix() {
}

double& Matrix::operator()(int r, int c) {
	assert(r >= 0 && r < row&& c >= 0 && c < col);
	return date[col * r + c];
}



/*double* p = new double[row * m.col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < m.col; j++)
			p[i][j] = 0;*/
Matrix Matrix::operator*(Matrix& m) {
	assert(col == m.row);
	shared_ptr<double[]> ptr(new double[100]);
	memset(ptr.get(), 0, 100 * sizeof(double));
	Matrix P(ptr, row, m.col);
	for (int i = 0; i < row; i++)
		for (int k = 0; k < m.col; k++)
			for (int j = 0; j < col; j++)
				P(i, k) += date[col * i + j] * m(j, k);

	return P;
}
void Matrix::Matshow() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << date[col * i + j] << ' ';
		cout << endl;
	}
}
