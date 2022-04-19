#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int main(void) {
	int isA;//是否为甲方
	int k;//0到25
	char M[100],C[100];
	M[99]=C[99] = '\0';
	printf("加密为1，解密为0:");
	scanf("%d", &isA);
	if (isA) {
		printf("输入密钥(0到25):");
		scanf("%d", &k);
		printf("输入内容:");
		scanf("%s", M);
		int length = strlen(M);

		for (int i = 0;i < length;i++) {
			C[i] = ((M[i] + k-65) % 26)+65;
		}
		printf("密文是:");
		for (int i = 0;i < length;i++) {
			printf("%c", C[i]);
		}
	}
	else
	{
		printf("输入密钥(0到25):");
		scanf("%d", &k);
		printf("输入密文:");
		scanf("%s", C);
		int length = strlen(C);
		for (int i = 0;i < length;i++) {
			M[i] = ((C[i] + 26-k-65) % 26)+65;
		}
		printf("原文是:");
		for (int i = 0;i < length;i++) {
			printf("%c", M[i]);
		}
	}



	return 0;
}