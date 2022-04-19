#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct fraction {
	long long int numerator;
	unsigned long long int denominator;

};
fraction Fra_Add(fraction f1, fraction f2);
fraction Fra_Sub(fraction f1, fraction f2);
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
	fraction f1, f2;
	scanf("%lld/%lld %lld/%lld", &f1.numerator, &f1.denominator, &f2.numerator, &f2.denominator);
	if (f1.denominator == 0 || f2.denominator == 0) {
		printf("{0, 0}");
	}
	else {
		fraction sum = { 0,1 };
		for (int i = 1; i <= 10; i ++) {
			if (i % 2 == 0)sum = Fra_Sub(sum, { 1,(unsigned long long)2 * i - 1 });
			else sum = Fra_Add(sum, { 1,(unsigned long long)2 * i - 1 });
		}

		sum.numerator *= 4;
		long long g = gcd(sum.numerator > 0 ? sum.numerator : (0 - sum.denominator), sum.denominator);
		sum.numerator = sum.numerator / g;
		sum.denominator = sum.denominator / g;
		printf("%lld/%lld\n", sum.numerator, sum.denominator);
	}

}

fraction Fra_Add(fraction f1, fraction f2)
{
	fraction ans = { f1.numerator * (long long int)f2.denominator + (long long int)f1.denominator * f2.numerator,f1.denominator * f2.denominator };
	long long g = gcd(ans.numerator > 0 ? ans.numerator : (0 - ans.denominator), ans.denominator);
	ans.numerator = ans.numerator / g;
	ans.denominator = ans.denominator / g;
	return ans;
}

fraction Fra_Sub(fraction f1, fraction f2)
{
	fraction ans = { f1.numerator * (long long int)f2.denominator - (long long int)f1.denominator * f2.numerator,f1.denominator * f2.denominator };

	long long g = gcd(ans.numerator > 0 ? ans.numerator : (0 - ans.numerator), ans.denominator);
	ans.numerator = ans.numerator / g;
	ans.denominator = ans.denominator / g;
	return ans;
}
