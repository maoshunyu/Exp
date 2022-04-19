#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int main() {
	char start, end;
	int flag = 0;
	char* s=(char*)malloc(140*sizeof(char));
	char* target = (char*)malloc(140 * sizeof(char));

	memset(target, 0, 140 * sizeof(char));
	printf("start: ");
	scanf("%c", &start);
	getchar();
	printf("end: ");
	scanf("%c", &end);
	getchar();
	printf("input:  \n");
	gets_s(s, 140);
	printf("output:\n");

	int index=0;
	for (int i = 0;i < strlen(s);i++) {
		if ( * (s + i) == start) {
			flag = 1;
			continue;
		}
		if (flag == 1) {
			if (*(s + i) == start) {
				memset(target, 0, 140 * sizeof(char));
				index = 0;
			}
			else if (*(s + i) == end) {
				flag = 0;
				printf("%s\n", target);
				memset(target, 0, 140 * sizeof(char));
				index = 0;
			}
			else {
				*(target + index) = *(s + i);
				index++;
			}
		}
	}
}