/*
 * @Descripttion:
 * @version:
 * @Author: Mao Shunyu
 * @Date: 2022-05-01 22:36:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-03 18:19:41
 */
#include <fstream>
#include <iostream>
#include <strstream>
using namespace std;
int main() {
  char* c = new char[500];
  char* d = new char[100];
  ostrstream strout(c, 500);
  ofstream w("workers.txt", ios::binary);
  ifstream workers("workers.txt", ios::binary);
  strout << 1 << " "
         << "Alice"
         << " "
         << "13999996328"
         << " "
         << "100084"
         << " "
         << "�������" << endl
         << 2 << " "
         << "Bob"
         << " "
         << "13836496328"
         << " "
         << "100084"
         << " "
         << "�廪԰�ֵ�" << endl
         << 3 << " "
         << "Carol"
         << " "
         << "139572386328"
         << " "
         << "100084"
         << " "
         << "New York" << endl
         << 4 << " "
         << "Elisa"
         << " "
         << "13985636328"
         << " "
         << "100084"
         << " "
         << "�������" << endl
         << '\0';
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
    } else {
      workers.getline(d, 100);
      cout << "id: " << id << d << endl;
      success = true;
      break;
    }
  }
  if (!success) cout << "����Ϣ" << endl;
  workers.close();
}
