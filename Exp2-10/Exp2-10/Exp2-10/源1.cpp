#include <iostream>
using namespace std;
template<class T>
class test
{
public:
	test(const int n,T src[]):len_(n),list_(new T[len_*sizeof(T)])
	{
		memcpy(list_, src, n*sizeof(T));
	}
	~test() {
		delete[] list_;
	}
	int len() const {
		return len_;
	}
	bool search(T dst);
private:
	int len_;


private:
	T* list_;
};

template <class T>
bool test<T>::search(T dst)
{
	bool exist = false;
	for (int i = 0; i < len_; ++i) {
		if(list_[i]==dst) {
			cout << "µÚ" << i + 1 << "¸ö" << endl;
			exist = true;
		}
	}
	if (!exist) {
		cout << "Î´ÕÒµ½" << endl;
		return false;
	}
	return true;

}

int main() {
	int a[] = { 543,52345,534,22,476,756,78,8,675 };
	char c[] = "fasdweroixsfqws";
	char* p = new char[sizeof(c) / sizeof(char)];
	strcpy_s(p, sizeof(c), c);

	test<int> ti(sizeof(a)/sizeof(int), a);
	test<char> tc(sizeof(c) / sizeof(char), c);
	test<char> tp(sizeof(c) / sizeof(char), p);

	ti.search(65);
	tc.search('s');
	tp.search('f');
}
