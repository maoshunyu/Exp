#include <stdio.h>
#include <cmath>
//double f(double x);
//double S(double a, double b, double m);
//int main() {
//	printf("%f", S(-1, 1, 2000));
//}
//double f(double x) {
//	return exp(-x * x);
//}
//double S(double a, double b, double m) {
//	double sum = 0;
//	double h = (b - a) / m;
//	for (;a <= b;a += h) {
//		sum += (f(a) + f(a + h)) * h / 2;
//	}
//	return sum;
//}
int main() {
	int x, y, z;//x��վ�ŵģ�y�����ŵģ�z���ϵ�
	/*
	  x+y+z=100
	  5x+3y+z/3=100
	  x,y,z>0
	*/
	for (x = 1;x <= 98;x++) {
		for (y = 1;y <= 98;y++) {
			z = 100 - x - y;
			if (z%3==0 && 5 * x + 3 * y + z / 3 == 100) {
				printf("վ�ŵ���%d  ���ŵ���%d ��ˮţ��%d  \n", x, y, z);
			}
		}
	}
}
