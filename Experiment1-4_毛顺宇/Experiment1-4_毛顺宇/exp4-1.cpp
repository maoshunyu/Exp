#include <stdio.h>
#include <cmath>
#define pi 3.1416
#pragma warning(disable: 4996)
int main() {
	double x,y;
	scanf("%lf %lf", &x,&y);
	printf("f(x)=%lf\n", (1/(sqrt(2*pi))*exp(-x*x/2)));
	printf("g(x)=%lf",(1.0/3.0) * sin(x * x + y * y) * cos(x + y));


	return 0;
}