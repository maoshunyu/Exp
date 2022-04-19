#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#pragma warning(disable:4996)
int main(int argc,char* argv[]) {
	if (argc != 2)exit(-1);
	FILE* f = fopen(argv[1], "r");
	char* str = (char*)malloc(81 * sizeof(char));
	fgets(str, 81, f);
	printf("%s\n³¤¶È£º%d", str, strlen(str));
	fclose(f);
}
/*
* Ö´ÐÐÃüÁî 
*	> Exp1-14.exe test.txt
* test.txt:
*	abcd  efg  s
* 
 */