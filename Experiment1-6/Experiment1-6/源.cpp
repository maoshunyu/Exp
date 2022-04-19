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
