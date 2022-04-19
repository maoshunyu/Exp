#include <iostream>
using namespace std;
class People {
public:
	class Date {
	public:
		Date(int y, int m, int d) :year(y), month(m), day(d) {
		}

		~Date() {
		}
		int year, month, day;
		friend ostream& operator <<(ostream& o, Date& d);
	private:

	};

	People(const char name[11], const char number[7], const char sex[3], const char id[16], int y, int m, int d) :birthday(y, m, d) {
		strcpy_s(this->name, 11, name);
		strcpy_s(this->number, 7, number);
		strcpy_s(this->sex, 3, sex);
		strcpy_s(this->id, 16, id);
		cout << "People constructed" << endl;
	}

	~People() {
		cout << "people desturcted" << endl;
	}
	People(const People& r) :birthday(r.birthday) {
		strcpy_s(this->name, 11, r.name);
		strcpy_s(this->number, 7, r.number);
		strcpy_s(this->sex, 3, r.sex);
		strcpy_s(this->id, 16, r.id);
	}
	inline void show() {
		cout << "name: " << name << "  " << "number: " << number << "  " << "sex: " << sex << "  " << "id:  " << id << "  " << "birthday:  " << birthday;
	}

	char name[11];
	char number[7];
	char sex[3];
	char id[16];
	Date birthday;
	void eject() {
		this->~People();
	}
private:

};
class teacher :public People {
public:
	teacher(const char name[11], const char number[7], const char sex[3], const char id[16], int y, int m, int d, const char ps[11], const char de[21]) :People(name, number, sex, id, y, m, d) {
		strcpy_s(this->principalship, 11, ps);
		strcpy_s(this->department, 21, de);
		cout << "teacher constructed" << endl;
	}
	teacher(const teacher& r) :People(r) {
		strcpy_s(this->principalship, 11, r.principalship);
		strcpy_s(this->department, 21, r.department);
	}
	~teacher() {
		cout << "teacher desturcted" << endl;
	}
	char principalship[11];
	char department[21];
	inline void show() {
		People::show();
		cout << "principalship: " << principalship << "  " << "department: " << department << "  ";
	}void eject() {
		this->~teacher();
	}
private:

};

class student :public People {
public:
	student(const char name[11], const char number[7], const char sex[3], const char id[16], int y, int m, int d, const char cn[7]) :People(name, number, sex, id, y, m, d) {
		strcpy_s(this->classNo, 7, cn);
		cout << "student constructed" << endl;
	}
	student(const student& r) :People(r) {
		strcpy_s(this->classNo, 7, r.classNo);
	}
	~student() {
		cout << "student desturcted" << endl;
	}

	char classNo[7];
	inline void show() {
		People::show();
		cout << "classNo: " << classNo << "  ";
	}
	void eject() {
		this->~student();
	}
private:

};
class graduate :public student {
public:
	graduate(const char name[11], const char number[7], const char sex[3], const char id[16], int y, int m, int d, const char cn[7], const char su[21], const char te[30]) :student(name, number, sex, id, y, m, d, cn) {
		strcpy_s(this->subject, 21, su);
		strcpy_s(this->advisor, 30, te);
		cout << "graduate constructed" << endl;
	}

	graduate(const graduate& r) :student(r){
		strcpy_s(this->subject, 21, r.subject);
		strcpy_s(this->advisor, 30, r.advisor);
	}
	~graduate() {
		cout << "graduate desturcted" << endl;
	}
	char subject[21];
	char advisor[30];
	inline void show() {
		student::show();
		cout << "subject: " << subject << "  " << "advisor: " << advisor << "  ";
	}
	void eject() {
		this->~graduate();
	}
private:

};
class TA :public teacher, public graduate {
public:
	TA(const char name[11], const char number[7], const char sex[3], const char id[16], int y, int m, int d, const char cn[7], const char su[21], const char te[30], const char ps[11], const char de[21]) :teacher(name, number, sex, id, y, m, d, ps, de), graduate(name, number, sex, id, y, m, d, cn, su, te) {
		cout << "TA constructed" << endl;
	}
	TA(const TA& r) :teacher(r), graduate(r) {

	}
	~TA() {
		cout << "TA desturcted" << endl;
	}
	inline void show() {
		graduate::show();
		cout << "principalship: " << principalship << "  " << "department: " << department << "  ";
	}
	void eject() {
		this->~TA();
	}
private:

};

int main() {
	TA ta("alice", "1", "wo", "12345678", 2003, 1, 1, "123456", "electronic", "yang fang", "ta", "department of ee");
	ta.show();


}

ostream& operator<<(ostream& o, People::Date& d) {
	o << d.year << "Äê " << d.month << "ÔÂ " << d.day << "ÈÕ ";
	return o;
}
