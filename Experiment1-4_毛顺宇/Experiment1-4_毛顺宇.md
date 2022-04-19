####第一题

![image-20211016173811286](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211016173811286.png)

```c
#include <stdio.h>
#include <cmath>
#define pi 3.1416
#pragma warning(disable: 4996)
int main() {
	double x,y;
	scanf("%lf %lf", &x,&y);
	printf("f(x)=%lf\n", (1/(sqrt(2*pi))*exp(-x*x/2)));
	printf("g(x)=%lf",(1.0/3.0) * sin(x * x + y * y) * cos(x + y));


	return 0;
}
```

---------
#### 第二题

1. x=0时为1，x=1时为0

2. 0

3. $a\in(-10,-5)且b=c$时为1，其余为0

4. 1
5. $0<y<5且5<b<6$时为1，其余为0
6. 1
7. $y<2且3<x<5$时为1，其余为0

-------

#### 第三题

![image-20211016173847762](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211016173847762.png)

```c
#include <stdio.h>
int main() {
	int a = 1,b = 0, c = 0;
	b = 0;
	c = 1;
	b = 1;
	if (a == 1 && b == 0 && c == 0)printf("甲在说谎");
	a = 0, b = 1, c = 0;
	b = 1;
	c = 0;
	b = 1;
	if (a == 0 && b == 1 && c == 0)printf("乙在说谎");
	a = 0, b = 0, c = 1;
	b = 1;
	c = 1;
	if (a == 0 && b == 0 && c == 1)printf("丙在说谎");
	return 0;
}
```

----------

#### 选做题

![image-20211016175057795](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211016175057795.png)

```c
#include <stdio.h>
int main() {
	int a, b, c;
	for (c = 100;c > 0;c--) {
		if (15 * c <= 1000) {
			if (1000 - 15 * c >= 15) {
				int rest_ab = 1000 - 15 * c;
				for (b = rest_ab / 10;b > 0;b--) {
					int rest_a = rest_ab - 10 * b;
					for (a = rest_a / 5;a > 0;a--) {
						printf("%d只小鸡%d只公鸡%d只母鸡\n", a, b, c);
					}
				}
				break;
			}
		}
	}
	return 0;
}

```

