#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int main(void) {
	int isA;//�Ƿ�Ϊ�׷�
	int k;//0��25
	char M[100],C[100];
	M[99]=C[99] = '\0';
	printf("����Ϊ1������Ϊ0:");
	scanf("%d", &isA);
	if (isA) {
		printf("������Կ(0��25):");
		scanf("%d", &k);
		printf("��������:");
		scanf("%s", M);
		int length = strlen(M);

		for (int i = 0;i < length;i++) {
			C[i] = ((M[i] + k-65) % 26)+65;
		}
		printf("������:");
		for (int i = 0;i < length;i++) {
			printf("%c", C[i]);
		}
	}
	else
	{
		printf("������Կ(0��25):");
		scanf("%d", &k);
		printf("��������:");
		scanf("%s", C);
		int length = strlen(C);
		for (int i = 0;i < length;i++) {
			M[i] = ((C[i] + 26-k-65) % 26)+65;
		}
		printf("ԭ����:");
		for (int i = 0;i < length;i++) {
			printf("%c", M[i]);
		}
	}



	return 0;
}