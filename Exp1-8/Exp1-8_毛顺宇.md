## 作业八

### 第一题

```c
//递推法
#include <ctime>
#include <stdio.h>
#include <string.h>
int main() {
	int state[40];
	memset(state, 0, sizeof(state));
	int num = 40;
	int cnt = 0;
	while (num>=2) {
		for (int i = 0;i < 40;i++) {
			if (state[i])continue;
			cnt++;
			if (cnt % 3 == 0) {
				state[i] = 1;
				num--;
			}
		}
	}
	for (int j = 0;j < 40;j++) {
		if (!state[j])printf("%d号\n", j);
	}
	clock_t clk = clock();
	printf("%d\n", clk);
  return 0;
}
```

![image-20211122171348931](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211122171348931.png)

```c
//递归法
#include <ctime>
#include <stdio.h>
int j(int num,int i);
int main() {
	printf("%d号\n", j(40,40));
	clock_t clk = clock();
	printf("时间：%d\n", clk);
}

int j(int num,int i)
{
	if (i == 1) return (num+2)%num;
	else {
		return (j(num-1,i - 1) + 3) % num;
	}
}
```

![image-20211122171438443](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211122171438443.png)

![image-20211122172010972](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211122172010972.png)

### 第二题

```c
#include <time.h>
#include <stdio.h>
#pragma warning(disable:4996)
long GoDown(long n);
int main() {
	clock_t t1, t2;
	double t;
	long n;
	scanf("%ld", &n);
	t1 = clock();
	printf("%ld\n", GoDown(n));
	t2 = clock();
	t = (double)(t2 - t1)/CLOCKS_PER_SEC;
	printf("%f\n",t);
}

long GoDown(long n)
{
	if (n == 1)return 1;
	else if (n == 2)return 2;
	else if (n == 3)return 4;
	else {
		return GoDown(n - 1) + GoDown(n - 2) * 2 + GoDown(n - 3) * 4;
	}
}

```

![image-20211122181706542](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20211122181706542.png)

n=15平均用时0.0000367s

n=25平均用时0.003184s

n=35平均用时1.58763s