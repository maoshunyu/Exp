#include <fstream>
#include <iostream>
using namespace std;
int main() {
  ofstream w("workers.txt", ios::binary);
  w << 1 << " "
    << "Alice"
    << " "
    << "13999996328"
    << " "
    << "100084"
    << " "
    << "�������" << endl;
  w << 2 << " "
    << "Bob"
    << " "
    << "13836496328"
    << " "
    << "100084"
    << " "
    << "�廪԰�ֵ�" << endl;
  w << 3 << " "
    << "Carol"
    << " "
    << "139572386328"
    << " "
    << "100084"
    << " "
    << "New York" << endl;
  w << 4 << " "
    << "Elisa"
    << " "
    << "13985636328"
    << " "
    << "100084"
    << " "
    << "�������" << endl;
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
    } else {
      workers.getline(data, 100);
      cout << "id: " << id << data << endl;
      success = true;
      break;
    }
  }
  if (!success) cout << "����Ϣ" << endl;
  workers.close();
}
