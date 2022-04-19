#include <stdio.h>
#pragma warning(disable: 4996)
int main(void){
	
	int x1, x2;
	unsigned int y;
	char c1,c2;
	x1 = 65535;
	x2 = x1 + 5;
	printf("enter y: ");
	scanf("%u", &y);//输入无符号整型y
	c1 = 97;
	c2 = 'A';
	c2 = c2 + 32;//转换成小写
	printf("x1=%d\n", x1);
	printf("x2=%d\n", x2);
	printf("y=%u\n", (y + 15));
	printf("c1=%c\n", c1);//打印对应的字符
	printf("c2=%c\n", c2);
	return(0);
}