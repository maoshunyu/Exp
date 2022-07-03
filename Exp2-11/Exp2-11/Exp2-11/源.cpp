#include <iostream>
#include <random>
#include <vector>
using namespace std;
int get_fib(int n);

int main(int argc, char* argv[]) {
  vector<int> a(100);
  random_device rd;
  const uniform_int_distribution<> dis(-10000, 10000);
  for (auto it = a.begin(); it != a.end(); ++it) { *it = dis(rd); }
  for (int i = 1;; ++i) {
    const int fib = get_fib(i);
    if (fib > 100) break;
    a.erase(a.begin() + fib - i);
  }
  sort(a.begin(), a.begin() + a.size() / 2);
  sort(a.begin() + a.size() / 2, a.end(), greater<>());
  for (const int a1 : a) { cout << a1 << endl; }
}

int get_fib(const int n) {
  static int fib[100];
  if (n <= 2) {
    fib[0] = -1;
    fib[1] = 1;
    fib[2] = 2;
  } else fib[n] = fib[n - 1] + fib[n - 2];
  return fib[n];
}
