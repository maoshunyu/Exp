#include <fstream>
#include <iostream>
using namespace std;
int main() {
	ifstream f("essay.txt");
	char* file = new char[31];
	int num = 0;
	while (f.good()) {
		f.getline(file, 30);
		cout << file << endl;
		num++;
	}
	cout << "ÐÐÊý£º " << num;
}