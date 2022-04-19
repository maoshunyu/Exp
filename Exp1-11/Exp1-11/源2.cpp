#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int index[10], a[10];
	int* pa[10];
	printf("input:\n");
	for (int i = 0;i < 10;i++) {
		scanf("%d", a+i);
		*(pa + i) = a + i;
	}
	for (int i = 0;i < 10;i++) {
		int min = **(pa + i);
		int k = i;
		for (int j = i;j < 10;j++) {
			if (**(pa + j) <= min) {
				min = **(pa + j);
				k = j;
			}
		}
		int temp = **(pa + i);
		**(pa + i) = min;
		**(pa + k) = temp;
		*(index + i) = k;
	}
	printf("\noutput: \n");
	for (int i = 0;i < 10;i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
	for (int i = 0;i < 10;i++) {
		printf("%d ", *(index + i));
	}
}
