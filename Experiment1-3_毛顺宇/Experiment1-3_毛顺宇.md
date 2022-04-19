#### 第一题

![image-20211012160233065](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211012160233065.png)

```c
#include <stdio.h>
#pragma warning(disable: 4996)
int main(void) {
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(unsigned short));
	printf("%d\n", sizeof(unsigned int));
	printf("%d\n", sizeof(unsigned long));
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(bool));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(float));
	printf("%d\n", (double)1);
	return 0;
}
```

-----

#### 第二题

![image-20211012160437262](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211012160437262.png)

```c
#include <stdio.h>
#pragma warning(disable: 4996)
int main(void) {
	char a = 32, b = 42;
	printf(" %c %c %c %c %c\n", b, a, a, a, b);
	printf(" %c %c %c %c %c\n", a,b,a,b,a);
	printf(" %c %c %c %c %c\n", a,a,b,a,a);
	printf(" %c %c %c %c %c\n", a,b,a,b,a);
	printf(" %c %c %c %c %c\n", b,a,a,a,b);
	return 0;
}
```

------

#### 第三题

![image-20211012160814033](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211012160814033.png)

```c
#include <stdio.h>
#include <math.h>
#pragma warning(disable: 4996)
int main(void) {
	for (int i = 1;i <= 6;i++) {
		printf("当前是%d 月 有%d 头羊 值%d 元\n", i, (int)pow(2, i + 1), (int)(10 * pow(2, i + 1)));
	}
	return 0;
}
```

----

####选做题

![image-20211012161030367](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211012161030367.png)

```c
#include <stdio.h>
#pragma warning(disable: 4996)
int main(void) {
	char n[12];
	printf("输入号码：");
	scanf("%s", n);
	printf("%s", n);
	return 0;
}
```

