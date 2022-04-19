### 第五次作业

#### 实验目的：判断三角形、有理数计算、数字分离

#### 实验环境：Windows11  MSVC

##### 第一题：

1. 流程图

   ![](C:\Users\Lenovo\Documents\清华\大一\程设\Experiment\Experiment1-5\绘图1.jpg)

2. 代码

   ```c
   #include <stdio.h>
   #pragma warning(disable: 4996)
   int main() {
   	int x, y, z;
   	scanf("%d %d %d", &x, &y, &z);
   	if (x+y>z && x+z>y && y+z>x) {
   		if (x == y || y == z || x == z) {
   			if (x == y == z) {
   				printf("Equilateral triangle");
   			}
   			else {
   				printf("Isosceles triangle");
   			}
   		}
   		else {
   			printf("Triangle");
   		}
   	}
   	else {
   		printf("Not triangle");
   	}
   	return 0;
   }
   ```

   

3. 结果

![image-20211028162609930](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211028162609930.png)

##### 第二题：

1. 流程

   ![绘图2](C:\Users\Lenovo\Documents\清华\大一\程设\Experiment\Experiment1-5\绘图2.jpg)

2. 代码

   ```c
   #include <stdio.h>
   #pragma warning(disable: 4996)
   int main() {
   	int a,b,c,d;
   	char at;
   	scanf("%c %d %d %d %d", &at, &a, &b, &c,&d);
   	if (b == 0 || d == 0 || (at == '/' && c == 0)) {
   		printf("input error");
   	}
   	else {
   		switch (at)
   		{
   		case '+':
   			printf("%.2f",a / (float)b + c / (float)d);
   			break;
   		case '-':
   			printf("%.2f", a / (float)b - c / (float)d);
   			break;
   		case '*':
   			printf("%.2f", a / (float)b * c / (float)d);
   			break;
   		case '/':
   			printf("%.2f", a / (float)b / (c / (float)d));
   			break;
   		}
   	}
   
   	return 0;
   }
   ```

   

3. 结果

   ![image-20211028164642201](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211028164642201.png)

##### 第三题：

1. 流程图

   ![绘图3](C:\Users\Lenovo\Documents\清华\大一\程设\Experiment\Experiment1-5\绘图3.jpg)

2. 代码

   ```c
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
   ```

   

3. 结果

   ![image-20211030230422772](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211030230422772.png)
