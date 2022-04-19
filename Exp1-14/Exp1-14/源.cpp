#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#pragma warning(disable:4996)
int main() {
	char* str = (char*)malloc(100 * sizeof(char));
	scanf("%s", str);
	int len = str ? strlen(str) : 0;
	for (int i = 0; i < len - 1; i++) {
		if (islower(str[i])) {
			str[i] = toupper(str[i]);
		}
	}
	FILE* f = fopen("upper.txt", "w");
	for (int i = 0; i < len - 1; i++) {
		fputc(str[i], f);
	}
	fclose(f);
	FILE* fp = fopen("upper.txt", "r");
	char* s = (char*)malloc(100 * sizeof(char));
	fscanf(fp, "%s", s);
	printf("%s\n", s);
	fclose(fp);
}