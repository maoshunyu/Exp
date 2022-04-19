#include <stdio.h>
#pragma warning(disable:4996)
void sort(int *a);
void merge(int *a, int *a1, int *a2);
int main() {
	int a[20] = { 0 }, a1[10], a2[10];
	for (int i = 0;i < 10;i++) {
		scanf("%d",&a1[i]);
	}
	for (int i = 0;i < 10;i++) {
		scanf("%d", &a2[i]);
	}
	sort(a1);
	sort(a2);
	merge(a, a1, a2);
	for (int i = 0;i < 20;i++) {
		printf("%d ", *(a+i));
	}
}

void sort(int *a)
{
	for (int i = 0;i < 10;i++) {
		int min = *(a + i);
		int k = i;
		for (int j = i;j < 10;j++) {
			if (*(a + j) <= min) {
				min = *(a + j);
				k = j;
			}
		}
		int temp = *(a + i);
		*(a + i) = min;
		*(a + k) = temp;
	}
}

void merge(int* a, int* a1, int* a2)
{
	int i = 0, j = 0;
	for (int k = 0;k < 20;k++) {
		if (i == 10) {
			*(a + k) = *(a2 + j);
			j++;
			continue;
		}
		if (j == 10) {
			*(a + k) = *(a1 + i);
			i++;
			continue;
		}
		if (*(a1 + i) <= *(a2 + j)) {
			*(a + k) = *(a1 + i);
			i++;
		}
		else {
			*(a + k) = *(a2 + j);
			j++;
		}
	}
	
}
