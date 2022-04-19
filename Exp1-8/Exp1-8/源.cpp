/*
 * @Descripttion: 
 * @version: 
 * @Author: Maoshunyu
 * @Date: 2021-11-22 16:03:31
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-11-22 18:14:26
 */
//#include <ctime>
//#include <stdio.h>
//#include <string.h>
//int main() {
//	int state[40];
//	memset(state, 0, sizeof(state));
//	int num = 40;
//	int cnt = 0;
//	while (num>=2) {
//		for (int i = 0;i < 40;i++) {
//			if (state[i])continue;
//			cnt++;
//			if (cnt % 3 == 0) {
//				state[i] = 1;
//				num--;
//			}
//		}
//	}
//	for (int j = 0;j < 40;j++) {
//		if (!state[j])printf("%d??\n", j);
//	}
//	clock_t clk = clock();
//	printf("???%d\n", clk);
//  return 0;
//}

//#include <ctime>
//#include <stdio.h>
//int j(int num,int i);
//int main() {
//	printf("%d??\n", j(40,40));
//	clock_t clk = clock();
//	printf("???%d\n", clk);
//}
//
//int j(int num,int i)
//{
//	if (i == 1) return (num+2)%num;
//	else {
//		return (j(num-1,i - 1) + 3) % num;
//	}
//}
#include <time.h>
#include <stdio.h>
#pragma warning(disable:4996)
long a[100] = { 1,2,4 };
int main() {
	clock_t t1, t2;
	double t;
	int n;
	t1 = clock();
	scanf("%d", &n);
	for (int i = 3;i < n;i++) {
		a[i] = a[i - 1] + 2 * a[i - 2] + 4 * a[i - 3];
	}
	t2 = clock();
	t = (double)(t2 - t1)/CLOCKS_PER_SEC;
	printf("%ld\n", a[n-1]);
	printf("%lf\n",t);
}


