//#include "stdio.h"
//#include "stdlib.h"
//#pragma warning(disable : 4996)
//int main(void)
//{
//	char a;
//	while (1) {
//		printf("小写:");
//		while ((a = getchar()) != '\n') {
//			printf("大写:");
//			putchar(a - 32);
//		}
//		putchar('\n');
//	}
//	return 0;
//}
////#include <stdio.h>
////#include <string.h>
////#pragma warning(disable:4996)
////
////void input(int *y, int* m, int* d);
////bool isLeapYear(int y);
////void printYear(int y); 
////void printMonth(int y, int m);
////void printDay(int y, int m, int d);
////int get_which_day(int y, int m, int d);
////bool is31(int i);
////bool have_to_stop(int y, int m, int d);
////
////
////int main(void)
////{
////    int y, m, d;
////    printf("请按输入顺序年、月、日\n");
////    printf("【注1：“年”为必需输入的数据且必须为1900及之后的年份，月、日为非必需选项，如不知道请输入0】\n");
////    printf("【注2：年、月、日中间请用空格隔开】\n");
////    input(&y, &m, &d);//用户输入日期
////    if(isLeapYear(y))printf("%d年是闰年\n\n", y);
////    else printf("%d年是平年\n\n", y);
////    if (d == 0) {
////        if (m == 0)printYear(y);
////        else printMonth(y, m);
////    }
////    else printDay(y,m,d);
////    return 0;
////}
////
////
/////*
////    1.用户输入
////    （1）已知年         >>>输出每月每日
////    （2）已知年、月         >>>输出当月每日
////    （3）已知年、月、日         >>>输出星期几
////*/
////void input(int* y, int* m, int* d){
////    scanf("%d%d%d", y, m, d);
////    //输入年月日后立马去判断是闰年还是平年
////}
////
////
////
////bool isLeapYear(int y){
////    //闰年
////    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)){
////        return true;
////    }
////    //非闰年
////    return false;
////}
////
////void printYear(int y){
////    for (int i = 1;i <= 12;i++) {
////        printMonth(y, i);
////    }
////}
////
////void printMonth(int y, int m){
////    printf("%d月\n\n", m);
////    printf("星期一     星期二     星期三     星期四     星期五     星期六     星期天     \n");
////    int day = get_which_day(y, m, 1);
////    for (int i = 1;;i++) {
////        if (i < day)printf("           ");
////        else {
////            printf("%-6d     ", i - day + 1);
////            if (i % 7 == 0)printf("\n");
////        }
////        if (have_to_stop(y, m, i - day + 1))break;
////    }
////    printf("\n\n");
////}
////
////void printDay(int y, int m, int d){
////    printf("%d年%d月%d日", y, m, d);
////    switch (get_which_day(y,m,d)) {
////    case 1:printf("星期一\n");break;
////    case 2:printf("星期二\n");break;
////    case 3:printf("星期三\n");break;
////    case 4:printf("星期四\n");break;
////    case 5:printf("星期五\n");break;
////    case 6:printf("星期六\n");break;
////    case 7:printf("星期天\n");break;
////    }
////}
/////*
////* @retval:1 ---> 7
////* 
////*/
////int get_which_day(int y, int m, int d){
////    //1900 1 1 ---> 1
////    int interval_day=0;
////    for (int i = 1900;i < y;i++) {
////        if (isLeapYear(i))interval_day += 366;
////        else interval_day += 365;
////    }
////
////    for (int i = 1;i < m;i++) {
////        if (i == 2) {
////            if (isLeapYear(y))interval_day += 29;
////            else interval_day += 28;
////        }
////        else if (is31(i))interval_day += 31;
////        else interval_day += 30;
////    }
////    interval_day += d - 1;
////    return interval_day % 7+1;
////}
////
////bool is31(int i)
////{
////    if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)return true;
////    return false;
////}
////
////bool have_to_stop(int y,int m,int d) {
////    if (m == 2) {
////        if (isLeapYear(y)) {
////            if (29 == d)return true;
////            else return false;
////        }
////        else {
////            if (28 == d)return true;
////            else return false;
////        }
////    }
////    else {
////        if (is31(m)) {
////            if (31 == d)return true;
////            else return false;
////        }
////        else {
////            if (30 == d)return true;
////            else return false;
////        }
////    }
////}
//
//
//    
//
//    

/*
 * @Descripttion:
 * @version:
 * @Author: Maoshunyu
 * @Date: 2021-12-09 22:09:25
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-12-09 22:14:28
 */
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main() {

    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d %d", a, b);
}