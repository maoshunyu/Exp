#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int a = 1,b = 0, c = 0;
	b = 0;
	c = 1;
	b = 1;
	if (a == 1 && b == 0 && c == 0)printf("����˵��");
	a = 0, b = 1, c = 0;
	b = 1;
	c = 0;
	b = 1;
	if (a == 0 && b == 1 && c == 0)printf("����˵��");
	a = 0, b = 0, c = 1;
	b = 1;
	c = 1;
	if (a == 0 && b == 0 && c == 1)printf("����˵��");
	return 0;
}