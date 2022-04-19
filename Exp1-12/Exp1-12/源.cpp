#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
void sort(char* p[20],int n);
int main() {
	int n;
	printf("input N: ");
	scanf("%d", &n);
	char* p[20];
	for (int i = 0;i < n;i++) {
		*(p + i) = (char*)malloc(sizeof(char*));
		scanf("%s", *(p+i));
	}
	sort(p,n);
	printf("output: \n");
	for (int i = 0;i < n;i++) {
		printf("%s\n", *(p + i));
	}
}

void sort(char* p[20],int n)
{
	for (int i = 0;i < n;i++) {
		char* min = *(p + i);
		int k = i;
		for (int j = i;j < n;j++) {
			if (strcmp(min, *(p + j)) > 0) {
				k = j;
				min = *(p + j);
			}
		}
		char* temp = *(p + i);
		*(p + i) = min;
		*(p + k) = temp;
	}
}
