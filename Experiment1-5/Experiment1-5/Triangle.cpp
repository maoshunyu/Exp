#include <stdio.h>
#pragma warning(disable: 4996)
int main() {
	int a,digits=1;
	int b[6] = { 0 };
	printf("please input an integer: ");
	scanf("%d", &a);
	int temp = a;
	printf("\nyour input:%d \n", a);
	while (temp / 10 != 0) {
		digits++;
		temp /= 10;
	}
	printf("num of digits:%d \n", digits);
	printf("each of digits: ");
	for (int i = 0;i < digits;i++) {
		b[i] = a % 10;
		a /= 10;
	}
	for (int i = 0;i < digits;i++) {
		if(i!=digits-1)printf("%d, ", b[digits - 1 - i]);
		else { printf("%d", b[digits - 1 - i]); }
	}
	printf("\n");
	printf("reversed order:");
	for (int i = 0;i<digits;i++) {
		if (b[i] != 0) {
			if(i!=digits-1)printf("%d, ", b[i]);
			else { printf("%d", b[i]); }
		}
	}
	return 0;
}