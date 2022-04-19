####第一题：

   ![image-20210925180931387](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20210925180931387.png)

short类型占两个字节，int和long类型占四个字节，char类型占一个字节

---------------------------------

####第二题：

​    ![img](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20210925180051687.png)

表明%hd是unsigned short类型（65535),%d使用int输出，而306587和28166459852都超出范围发生了截断

-----------------

####第三题：

![image-20210925180830364](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20210925180830364.png)![image-20210925180837025](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20210925180837025.png)

----------------

####选做题第一题：



![img](file:///C:/Users/Lenovo/AppData/Local/Temp/msohtmlclip1/01/clip_image002.png)![img](file:///C:/Users/Lenovo/AppData/Local/Temp/msohtmlclip1/01/clip_image003.png)

------------

#### 选做题第二题：

```c
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
```



