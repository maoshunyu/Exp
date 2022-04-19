//#include <stdio.h>
//#include <stdlib.h>
//#define N 300
////int main() {
////	int a[N],pos ;
////	for (int i = 0;i < N;i++) {
////		a[i]= 50 + rand() % 101;
////	}
////	for (int i = 0;i < N;i++) {
////		int max = a[i];
////		for (int j = i;j < N;j++) {
////			if (a[j] >= max) {
////				max = a[j];
////				pos = j;
////			}
////		}
////		int temp = a[i];
////		a[i] = a[pos];
////		a[pos] = temp;
////	}
////	for (int i = 0;i < 100;i++) {
////		printf("%d\n", a[i]);
////	}
////
////	return 0;
////}
//void sort(int a[],int l,int r);
//void sort(int a[],int l,int r)
//{
//    if (l < r) {
//        int i, j, x;
//
//        i = l;
//        j = r;
//        x = a[i];
//        while (i < j)
//        {
//            while (i < j && a[j] > x)
//                j--;
//            if (i < j)
//                a[i++] = a[j];
//            while (i < j && a[i] < x)
//                i++;
//            if (i < j)
//                a[j--] = a[i];
//        }
//        a[i] = x;
//        sort(a, l, i - 1);
//        sort(a, i + 1, r);
//    }
//}
//int main() {
//    int a[N];
//    for (int i = 0;i < N;i++) {
//        a[i] = 50 + rand() % 101;
//    }
//    sort(a, 0, N - 1);
//    for (int i = N-1;i >=200;i--) {
//        printf("%d\n", a[i]);
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//void swap_row(int row1, int row2);
//double a[4][4] = { {1.1161,0.1254,0.1397,0.1490},{0.1582,1.1675,0.1768,0.1871},{0.2368,0.2471,0.2568,1.2671},{0.1968,0.2071,1.2168,0.2271} };
//double b[4] = { 1.5471,1.6471,1.8471,1.7471 };
//double x[4];
//void swap_row(int row1, int row2)
//{//交换行列
//	double temp;
//	for (int j=0;j <=3;j++) {
//		temp = a[row1][j];
//		a[row1][j] = a[row2][j];
//		a[row2][j] = temp;
//	}
//	temp = b[row1];
//	b[row1] = b[row2];
//	b[row2] = temp;
//}
//int main() {
//	printf("MAT A = \n");
//	for (int i = 0;i <= 3;i++) {
//		printf("    ");
//		for (int j = 0;j <= 3;j++)printf("%.4f   ", a[i][j]);
//		printf("\n");
//	}
//	printf("MAT B = \n");
//	for (int i = 0;i <= 3;i++) {
//		printf("    %.4f", b[i]);
//	}
//	printf("\n\n");
//	for (int k = 0;k < 3;k++) {
//		double max = fabs(a[k][k]);
//		int pos = k;
//		for (int i = k;i <= 3;i++) {
//			if (fabs(a[i][k]) >= max) {
//				max = fabs(a[i][k]);
//				pos = i;
//			}
//		}
//		swap_row(k,pos);
//		for (int j = k+1;j <= 3;j++) {
//			a[k][j] /= a[k][k];
//		}
//		b[k] /= a[k][k];
//		for (int i = k + 1;i <= 3;i++) {
//			for (int j = k + 1;j <= 3;j++) {
//				a[i][j] = a[i][j] - a[i][k] * a[k][j];
//			}
//		}
//		for (int i = k + 1;i <= 3;i++) {
//			b[i] = b[i] - a[i][k] * b[k];
//		}
//	}
//	x[3] = b[3] / a[3][3];
//	for (int i = 2;i >=0;i--) {
//		double sum=0;
//		for (int j = i + 1;j <= 3;j++)sum += a[i][j] * x[j];
//		x[i] = b[i] - sum;
//	}
//	for (int i = 0;i <= 3;i++) {
//		printf("    x(%d) = %.4f\n", i+1 ,x[i]);
//	}
//	return 0;
//}

#include <stdio.h>
func(float a);
int main() {
	int x, y;
	/*
	* x+y=15
	* 2x+4y=40
	* */
	for (x = 0;x <= 15;x++) {
		y = 15 - x;
		if (2 * x + 4 * y == 40)break;
	}
	printf("鸡有%d只  兔有%d只  \n", x, y);
	int a = (x, y);
	printf("%d", a);
	return 0;
}