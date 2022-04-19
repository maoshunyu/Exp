#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int index[100];
char* ans;
char* s;
void p(int*  a,int begin,int n,int len_index);
void main(void) {
	//"1" == 49 
	// a == 97
	s = (char*)malloc(100 * sizeof(char));
	ans = (char*)malloc(100 * sizeof(char));
	memset(ans, 0, 100);
	scanf("%s", s);
	int n = strlen(s);
	int ind = 0;
	for (int i = 0; i < n; i++) {
		if ((s[i] - 48) * 10 + s[i + 1] - 48 > 0 && (s[i] - 48) * 10 + s[i + 1] - 48 < 27) {
			index[ind] = i;
			ind++;
		}
	}

	int a[100] = { 0 };
	int sum = 1;
	for (int i = 1; i < 100; i++) {
		if (index[i] != 0)sum++;
		else break;
	}
	if (sum == 1 && index[0] == 0)sum = 0;

	p(a,0,n,sum);

	return 0;
}
int j = 0;
int po = 0;
int times = 0;
void p(int* a,int begin,int n, int len_index) {
	if (begin == len_index-1) {
		if (len_index == 0) {
			for (int i = 0; i < n; i++) {
				printf("%c", s[i] + 48);
			}
			printf("\n");
			return;
		}
		else {
			a[len_index - 1] = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == 48) {
					continue;
				}
				if (i == index[j]) {
					if (a[j] == 0) {
						ans[po] = s[i] + 48;
						po++;
					}
					else {
						ans[po] = (s[i] - 48) * 10 + s[i + 1] - 48 + 96;
						po++;
						i++;
						if (index[j + 1] - index[j] == 1 && a[j + 1]) {
							j++; 
							if(times)goto l;
							times++;
						}
					}
					j++;
				}
				else {
					ans[po] = s[i] + 48;
					po++;
				}
			}
			
			printf("%s", ans);
			printf("\n");
			times = 0;
		l:
			j = 0;
			po = 0;
			memset(ans, 0, 100);

			a[len_index - 1] = 1;
			for (int i = 0; i < n; i++) {
				if (s[i] == 48) {
					continue;
				}
				if (i == index[j]) {
					if (a[j] == 0) {
						ans[po] = s[i] + 48;
						po++;
					}
					else {
						ans[po] = (s[i] - 48) * 10 + s[i + 1] - 48 + 96;
						po++;
						i++;
						if (index[j + 1] - index[j] == 1 && a[j + 1]) {
							j++;
							if (times)goto m;
							times++;
						}
					}
					j++;
				}
				else {
					ans[po] = s[i] + 48;
					po++;
				}
			}
			
			printf("%s", ans);
			printf("\n");
			times = 0;
		m:
			j = 0;
			po = 0;
			memset(ans, 0, 100);
		}
		
		return;
	}
	else {
		a[begin] = 0;
		p(a, begin + 1,n,len_index);
		a[begin] = 1;
		p(a, begin + 1,n,len_index);
	}
}