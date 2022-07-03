/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:21:31
 */
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
vector<int> fac({1, 1});
int get_fac(int pos);
inline int ncr(int n, int m);
int main() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 9 - i; j++) cout << "   ";
    for (int j = 0; j <= i; j++)
      cout << setw(6) << setiosflags(ios::left) << ncr(i, j);

    cout << endl;
  }
}

int get_fac(int pos) {
  while (fac.size() <= pos) { fac.push_back(fac.back() * fac.size()); }
  return fac.at(pos);
}

inline int ncr(int n, int m) {
  return get_fac(n) / (get_fac(m) * get_fac(n - m));
}
//#include <iostream>
// using namespace std;
// int main() {
//	int sum_a = 0, sum_b = 0, sum_c = 0, sum_d=0;
//	int m, n;
//	cin >> m >> n;
//
//	int* a = new int[100];
//	int** b = new int* [20];
//	int*** c = new int** [9];
//	int** d = new int* [m];
//
//	for (int i = 0; i < 100; i++) {
//		a[i] = i;
//		sum_a += a[i];
//	}
//	for (int i = 0; i < 20; i++) {
//		b[i] = new int[25];
//		for (int j = 0; j < 25; j++) {
//			b[i][j] = i * 25 + j;
//			sum_b += b[i][j];
//		}
//	}
//	for (int i = 0; i < 9; i++) {
//		c[i] = new int* [8];
//		for (int j = 0; j < 8; j++) {
//			c[i][j] = new int[5];
//			for (int k = 0; k < 5; k++) {
//				c[i][j][k] = i * 100 + j * 10 + k;
//				sum_c += c[i][j][k];
//			}
//		}
//	}
//	for (int i = 0; i < m; i++) {
//		d[i] = new int[n];
//		for (int j = 0; j < n; j++) {
//			d[i][j] = i * n + j;
//			sum_d += d[i][j];
//		}
//	}
//
//	delete[] a;
//	for (int i = 0; i < 20; i++) {
//		delete[] b[i];
//	}
//	delete[] b;
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 8; j++) {
//			delete[] c[i][j];
//		}
//		delete[] c[i];
//	}
//	delete[] c;
//	for (int i = 0; i < m; i++) {
//		delete[] d[i];
//	}
//	delete[] d;
//	cout << "sum_a:" << sum_a << "  " << "sum_b:" << sum_b << "  " <<
//"sum_c:" << sum_c << "  " << "sum_d:" << sum_d << "  " << endl;
//}