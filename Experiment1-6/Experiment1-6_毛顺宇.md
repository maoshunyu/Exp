#### 第一题：

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#pragma warning(disable:4996)
bool isprime(int a);
int main() {
	for (int i = 11;i <= 200;i += 2) {
		if (isprime(i) && isprime(i + 2))printf("%d %d\n", i, i + 2);
	}


	return 0;
}
bool isprime(int a) {
	for (int i = 2;i <= sqrt(a);i++) {
		if (a % i == 0)return false;
	}
	return true;
}
```

![image-20211107200102941](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211107200102941.png)

![绘图1](C:\Users\Lenovo\Documents\清华\大一\程设\Experiment\Experiment1-6\绘图1.jpg)

#### 第二题

```c
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main() {
	int n;
	printf("input n:");
	scanf("%d", &n);
	printf("output:\n");
	if (n > 2 && n % 2 != 0) {
		for (int i = 1;i <= n;i++) {
			if (i <= (n - 1) / 2) {
				for (int j = 1;j <= (n - 1) / 2-i+1;j++) {
					printf(" ");
				}
				for (int j = 1;j <= 2*i-1;j++) {
					printf("*");
				}
				printf("\n");
			}
			else {
				for (int j = 1;j <= (n - 1) / 2 - n + i;j++) {
					printf(" ");
				}
				for (int j = 1;j <= 2*(n-i+1)-1;j++) {
					printf("*");
				}
				printf("\n");
			}
		}
	}else{
		printf("Input Error");
	}
	return 0;
}

```

![image-20211107202604012](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211107202604012.png)

![绘图2](C:\Users\Lenovo\Documents\清华\大一\程设\Experiment\Experiment1-6\绘图2.jpg)

#### 第三题

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#pragma warning(disable:4996)
bool isprime(int a);
int main() {
	int n;
	scanf("%d", &n);
	if (n >= 4 && n % 2 == 0) {
		for (int i = 2;i <= n;i++) {
			if (isprime(i) && isprime(n - i)) {
				printf("%d = %d + %d", n, i, n - i);
				break;
			}
		}
	}
	else printf("Input Error");
	return 0;
}
bool isprime(int a) {
	for (int i = 2;i <= sqrt(a);i++) {
		if (a % i == 0)return false;
	}
	return true;	
}

```

![image-20211109154725957](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211109154725957.png)

![绘图3](C:\Users\Lenovo\Documents\清华\大一\程设\Experiment\Experiment1-6\绘图3.jpg)
