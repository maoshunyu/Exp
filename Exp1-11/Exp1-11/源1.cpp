#include <stdio.h>
#pragma warning(disable:4996)
void del(int* p, int n);
int main() {
	int n, num[50]={0};
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		*(num+i) = i + 1;
	}
	del(num, n);

	for (int i = 0;i < n;i++) {
		if (*(num + i) != 0)printf("%d  ", *(num+i));
	}
}

void del(int* p, int n)
{
	int count = 0;
	int i = 1, j = 0;

	while (count < n-2) {
		if (j == n)j = 0;
		if (*(p + j) == 0) {
			j++;
			continue;
		}
		else {
			if (i == 3) {
				*(p + j) = 0;
				count++;
				j++;
				i = 1;
			}
			else {
				j++;
				i++;
			}
		}
	}
}
