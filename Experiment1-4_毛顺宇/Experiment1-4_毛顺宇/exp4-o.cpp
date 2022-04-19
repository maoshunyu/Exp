#include <stdio.h>
#pragma warning(disable: 4996)
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
