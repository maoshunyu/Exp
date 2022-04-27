# 第九次作业

## 第一题

```cpp
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
	cout << "行数： " << num;
    f.close();
}
```



![image-20220427174433490](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427174433490.png)

---------------

## 第二题

```cpp
#include <fstream>
#include <iostream>
using namespace std;
int main() {
	ofstream w("workers.txt", ios::binary);
	w << 1 << " " << "Alice" << " " << "13999996328" << " " << "100084" << " " << "翻斗大街" << endl;
	w << 2 << " " << "Bob" << " " << "13836496328" << " " << "100084" << " " << "清华园街道" << endl;
	w << 3 << " " << "Carol" << " " << "139572386328" << " " << "100084" << " " << "New York" << endl;
	w << 4 << " " << "Elisa" << " " << "13985636328" << " " << "100084" << " " << "翻斗大街" << endl;
	w.close();
	ifstream workers("workers.txt", ios::binary);
	int id;
	cin >> id;
	bool success = false;
	char* data = new char[100];
	while (workers.good()) {
		int curid;
		workers >> curid;
		if (curid != id) {
			workers.getline(data, 100);
		}
		else {
			workers.getline(data, 100);
			cout << "id: " << id << data << endl;
			success = true;
			break;
		}
	}
	if (!success)cout << "无信息" << endl;
	workers.close();
}
```

![image-20220427181319090](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427181319090.png)

-------------------

## 第三题

```cpp
#include <fstream>
#include <iostream>
#include <strstream>
using namespace std;
int main() {
	char* c=new char[500];
	char* d = new char[100];
	ostrstream strout(c,500);
	ofstream w("workers.txt", ios::binary);
	ifstream workers("workers.txt", ios::binary);
	strout << 1 << " " << "Alice" << " " << "13999996328" << " " << "100084" << " " << "翻斗大街" << endl
		   << 2 << " " << "Bob" << " " << "13836496328" << " " << "100084" << " " << "清华园街道" << endl
		   << 3 << " " << "Carol" << " " << "139572386328" << " " << "100084" << " " << "New York" << endl
		   << 4 << " " << "Elisa" << " " << "13985636328" << " " << "100084" << " " << "翻斗大街" << endl<<'\0';
	w << c;
	w.close();
	int id;
	cin >> id;
	bool success = false;
	while (workers.good()) {
		int curid;
		workers >> curid;
		if (curid != id) {
			workers.getline(d, 100);
		}
		else {
			workers.getline(d, 100);
			cout << "id: " << id << d << endl;
			success = true;
			break;
		}
	}
	if (!success)cout << "无信息" << endl;
	workers.close();
}


```

![image-20220427181319090](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427181319090.png)

-----------------

## 第四题

![image-20220427184116192](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220427184116192.png)