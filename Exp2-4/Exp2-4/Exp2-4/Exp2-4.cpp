/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:21:24
 */
#include <iostream>
using namespace std;
class People {
public:
  class Date {
  public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    ~Date() {}
    int year, month, day;
    friend ostream& operator<<(ostream& o, Date& d);

  private:
  };

  char name[11];
  char number[7];
  char sex[3];
  char id[16];
  Date birthday;
  People(const char name[11], const char number[7], const char sex[3],
         const char id[16], int y, int m, int d)
      : birthday(y, m, d) {
    strcpy_s(this->name, 11, name);
    strcpy_s(this->number, 7, number);
    strcpy_s(this->sex, 3, sex);
    strcpy_s(this->id, 16, id);
  }

  ~People() {}
  People(const People& r) : birthday(r.birthday) {
    strcpy_s(this->name, 11, r.name);
    strcpy_s(this->number, 7, r.number);
    strcpy_s(this->sex, 3, r.sex);
    strcpy_s(this->id, 16, r.id);
  }
  inline void show() {
    cout << "name: " << name << "  "
         << "number: " << number << "  "
         << "sex: " << sex << "  "
         << "id:  " << id << "  "
         << "birthday:  " << birthday;
  }

private:
};

int main() {
  People p("alice", "1", "wo", "12345678", 2003, 1, 1);
  People p1(p);
  p1.show();
}

ostream& operator<<(ostream& o, People::Date& d) {
  o << d.year << "年 " << d.month << "月 " << d.day << "日 ";
  return o;
}
