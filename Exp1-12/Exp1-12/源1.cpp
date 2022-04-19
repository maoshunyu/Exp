#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int plus(int i, int n);
int main() {
	int a[10][10];
	int s[10]={0};
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			*(* (a + i) + j) = i * 10 + j;
		}
	}
	for (int n = 0;n < 10;n++) {
		for (int i = 1;i <= 10;i++) {
			*(s+n) += *(* (a + i - 1) + plus(i - 1, n));
		}
	}
	for (int i = 0;i < 10;i++) {
		printf("µÚ%d¶Ô½ÇÏß£º %d  \n", i, *(s+i));
	}
}

int plus(int i, int n)
{
	if ((i + n) <= 9)return i + n;
	else return (i + n) % 10;
}
