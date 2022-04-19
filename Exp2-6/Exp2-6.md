# 第六次作业

## 第一题

```cpp
#include <iostream>
using namespace std;
class Person {
public:
	Person(const char* n, char s, int a) :name(n), sex(s), age(a) {};
	~Person(){};

private:
protected:
	const char* name;
	char sex;
	int age;
};
class Employee :public Person {
public:
	Employee(const char* n, char s, int a,int bs,int ld):Person(n,s,a), basicSalary(bs), leaveDays(ld) {}
	~Employee() {
	}
	void show() {
		cout << "姓名： " << name <<endl<< "性别:  " << sex <<endl<< "年龄： " << age <<endl<< "基本工资:  " << basicSalary <<endl<< "请假天数： " << leaveDays << endl;
	}
private:
protected:
	int basicSalary;
	int leaveDays;
};
class Manager :public Employee{
public:
	Manager(const char* n, char s, int a, int bs, int ld,float p):Employee(n,s,a,bs,ld),performance(p) {
	}

	~Manager() {
	}
	void show() {
		Employee::show();
		cout << "业绩: " << performance << endl;
	}
private:
protected:
	float performance;
};


int main()
{
	char* name = new char (20);
	char sex;
	int age;
	int bs;
	int ld;
	float perf;
	cin >> name >> sex >> age >> bs >> ld >> perf;
	Manager m(name,sex,age,bs,ld,perf);
	m.show();
}


```

![image-20220324140415915](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220324140415915.png)

------------

## 第二题

![image-20220324141313195](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220324141313195.png)

**(1)**![image-20220324141601779](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220324141601779.png)

由于private继承，Base::print是Derived的private成员函数，不可在类外访问

**(2)**![image-20220324141800039](C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20220324141800039.png)

由于protected继承，Base::print是Derived的protected成员函数，不可在类外访问