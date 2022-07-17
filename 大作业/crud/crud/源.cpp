/*
 * @Descripttion: 程设大作业
 * @version: 1.0
 * @Author: Mao Shunyu
 * @Date: 2022-06-27 16:21:08
 * @LastEditors: Do not edit
 * @LastEditTime: 2022-07-13 12:48:48
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <variant>
#include <vector>
using namespace std;

/*-------------------------------------------变量-------------------------------------------*/
class Log;
vector<Log*> logs;
/*-------------------------------------------声明-------------------------------------------*/
void view();
void add();
void del();
void change();
void display(int choose, int main_index, int sub_index, bool is_reverse);
/*-------------------------------------------类-------------------------------------------*/
class dat {
public:
  dat(string& student_id, string& name, string& course, double score)
      : student_id(student_id),
        name(name),
        course(course),
        score(score){};  //储存基本信息
  int id;
  string student_id;
  string name;
  string course;
  double score;
  virtual variant<string, double> operator[](int i) {
    switch (i) {
      case 1: return id;
      case 2: return student_id;
      case 3: return name;
      case 4: return course;
      case 5: return score;
      default: return -1;
    }
  }
};

class Log : public dat {
private:
  static int max_id;

public:
  Log(string& student_id, string& name, string& course, double score,
      int id = 0);
  virtual ~Log();
  virtual void print(ostream& out) = 0;
  virtual void write(ofstream& out) = 0;
  virtual void set(string& student_id, string& name, string& course,
                   double score) {
    this->student_id = student_id;
    this->name = name;
    this->course = course;
    this->score = score;
  };
  virtual void set_grade(string& grade) = 0;
  static void get_max_id(int except = -1);
};

class Undergraduate_Log : virtual public Log {
public:
  string grade;
  Undergraduate_Log(string& student_id, string& name, string& course,
                    double score, string& grade, int id = 0)
      : Log(student_id, name, course, score, id), grade(grade){};
  /**
   * @msg: 打印到屏幕
   * @param {ostream&} out 输出
   * @return {*}
   */
  virtual void print(ostream& out) {
    out << id << "\t" << student_id << "\t" << name << "\t" << course << "\t"
        << score << "\t"
        << "本科生"
        << "\t" << grade;
  }

  /**
   * @msg: 输出到文件
   * @param {ofstream&} out 输出
   * @return {*}
   */
  virtual void write(ofstream& out) {
    out << id << "," << student_id << "," << name << "," << course << ","
        << score << ","
        << "本科生"
        << "," << grade << endl;
  }
  void set_grade(string& grade) { this->grade = grade; }
  variant<string, double> operator[](int i) {
    if (i == 6) return "本科生";
    else if (i == 7) return grade;
    else return Log::operator[](i);
  }
};
class Graduate_Log : virtual public Log {
public:
  string grade;
  Graduate_Log(string& student_id, string& name, string& course, double score,
               string& grade, int id = 0)
      : Log(student_id, name, course, score, id), grade(grade){};

  virtual void print(ostream& out) {
    out << id << "\t" << student_id << "\t" << name << "\t" << course << "\t"
        << score << "\t"
        << "研究生"
        << "\t" << grade;
  }
  virtual void write(ofstream& out) {
    out << id << "," << student_id << "," << name << "," << course << ","
        << score << ","
        << "研究生"
        << "," << grade << endl;
  }
  void set_grade(string& grade) { this->grade = grade; }
  variant<string, double> operator[](int i) {
    if (i == 6) return "研究生";
    else if (i == 7) return grade;
    else return Log::operator[](i);
  }
};

Log::Log(string& student_id, string& name, string& course, double score, int id)
    : dat(student_id, name, course, score) {
  get_max_id();
  //设定新纪录的id
  if (id == 0) {
    this->id = max_id + 1;
    Log::max_id = this->id;
  } else this->id = id;
}

Log::~Log() { get_max_id(this->id); }

int Log::max_id = 0;

/*-------------------------------------------方法-------------------------------------------*/
vector<string> stringSplit(const string& str, char delim) {
  stringstream ss(str);
  string item;
  vector<std::string> elems;
  while (getline(ss, item, delim)) {
    if (!item.empty()) { elems.push_back(item); }
  }
  return elems;
}
/**
 * @msg: 更新所有记录中的最大id
 * @param {int} except 忽略的元素
 * @return {*}
 */
void Log::get_max_id(int except) {
  if (logs.size() == 0) {
    max_id = 0;
  } else {
    int max = 0;
    for (int i = 0; i < logs.size(); i++) {
      if (logs[i]->id != except && logs[i]->id > max) {
        max = logs[i]->id;
        max = logs[i]->id;
      }
    }
    max_id = max;
  }
}
/*-----------------------------------------------------------------------*/
void display(int choose, int main_index, int sub_index, bool is_reverse) {
  vector<int> indexes;
  //选择要查看的条目
  if (choose == 9) return;
  else if (choose == 1)
    for (int i = 0; i < logs.size(); i++) indexes.push_back(i);
  else {
    string t;
    variant<string, double> temp;
    cout << "输入：";
    cin >> t;
    if (choose == 5) temp = atof(t.c_str());
    else temp = t;
    for (int i = 0; i < logs.size(); i++) {
      //查找对应的条目
      if ((choose != 5 && (*logs[i])[choose] == temp) ||
          (choose == 5 &&
           abs(get<double>(temp) - get<double>((*logs[i])[choose])) <= 1.0e-4))
        indexes.push_back(i);
    }
  }

  //排序
  sort(indexes.begin(), indexes.end(), [=](int a, int b) {
    return (((*logs[a])[main_index] == (*logs[b])[main_index])
                ? (*logs[a])[sub_index] < (*logs[b])[sub_index]
                : (*logs[a])[main_index] < (*logs[b])[main_index]);
  });
  if (is_reverse) reverse(indexes.begin(), indexes.end());

  cout << "id\t学号\t\t姓名\t课程\t成绩\t学历\t年级" << endl;
  for (auto&& i : indexes) {
    logs[i]->print(cout);
    cout << endl;
  }
}

void view() {
  cout << "输入: 内容 [-m] [-s] [-r]" << endl;
  cout << "\t内容: \t1 查看所有成绩 \t2 查看某个学号的成绩 \t3 "
          "查看某名学生成绩 \t4 查看某科目成绩 \t5 查看某一分数的学生 \t6 "
          "查看某学历学生的记录 \t7 查看某年级的成绩 \t9 返回"
       << endl;
  cout << "\t-m 主顺序: \t1 id \t2 学号 \t3 姓名 \t4 科目 \t5 成绩 \t默认: id"
       << endl;
  cout << "\t-s 次顺序: \t1 id \t2 学号 \t3 姓名 \t4 科目 \t5 成绩 \t默认: 学号"
       << endl;
  cout << "\t-r 开启反序: \t默认: 否" << endl;
  // example:    1 -m 1 -s 2 -r
  string line;
  getchar();
  getline(cin, line);
  vector<string> v = stringSplit(line, ' ');
  map<string, int> m;  //记录每个参数的位置
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i)[0] == '-') { m[v.at(i).substr(1, v.at(i).size() - 1)] = i; }
  }
  //遍历map
  int main_index = 1, sub_index = 2;
  bool is_reverse = false;
  for (auto&& arg : m) {
    const string a = arg.first;
    if (a == "m") {
      main_index = stoi(v.at(arg.second + 1));
    } else if (a == "s") {
      sub_index = stoi(v.at(arg.second + 1));
    } else if (a == "r") {
      is_reverse = true;
    } else {
      cout << "输入错误！" << endl;
      return;
    }
  }
  display(stoi(v.at(0)), main_index, sub_index, is_reverse);
}
/*-----------------------------------------------------------------------*/
void add() {
  cout << "请输入学号 姓名 科目 分数 学历 年级，以空格分隔" << endl;
  string a, b, c;
  double d;
  string e, f;
  cin >> a >> b >> c >> d >> e >> f;
  ofstream file("data.csv", ios::app);
  Log* log;
  if (e == "本科生") log = new Undergraduate_Log(a, b, c, d, f);
  else if (e == "研究生") log = new Graduate_Log(a, b, c, d, f);
  logs.push_back(log);
  log->write(file);
  cout << "添加成功" << endl;
  file.close();
}
/*-----------------------------------------------------------------------*/
void del() {
  cout << "请输入要删除成绩的id" << endl;
  int id;
  cin >> id;
  bool have_found = false;
  for (auto it = logs.begin(); it != logs.end(); it++) {
    if ((*it)->id == id) {
      have_found = true;
      (*it)->print(cout);
      cout << endl;
      delete *it;
      *it = nullptr;
      logs.erase(it);  //删除这条记录
      break;
    }
  }
  if (have_found) {
    ofstream file("data.csv", ios::out);
    for (int i = 0; i < logs.size(); i++) logs[i]->write(file);  //重新写入
    cout << "删除成功" << endl;
    file.close();
  } else cout << "未找到该成绩记录!" << endl;
}
/*-----------------------------------------------------------------------*/
void change() {
  cout << "请输入要修改成绩的id" << endl;
  int id;
  cin >> id;
  bool have_found = false;
  for (auto it = logs.begin(); it != logs.end(); it++) {
    if ((*it)->id == id) {
      have_found = true;
      cout << "请输入学号 姓名 科目 分数 学历 年级，以空格分隔" << endl;
      string a, b, c;
      double d;
      string e, f;
      cin >> a >> b >> c >> d >> e >> f;
      (*it)->set(a, b, c, d);
      (*it)->set_grade(f);
      break;
    }
  }
  if (have_found) {
    ofstream file("data.csv", ios::out);
    for (int i = 0; i < logs.size(); i++) logs[i]->write(file);
    cout << "修改成功" << endl;
    file.close();
  } else cout << "未找到该成绩记录!" << endl;
}
/*-----------------------------------------------------------------------*/
int main(int argc, char const* argv[]) {
  ifstream file("data.csv");
  if (!file) {
    cout << "文件打开失败" << endl;
    return 0;
  }
  string line;
  //读取文件内容
  while (getline(file, line)) {
    vector<string> strs = stringSplit(line, ',');
    if (!strs.empty()) {
      Log* log;
      if (strs[5] == "本科生")
        log = new Undergraduate_Log(strs[1], strs[2], strs[3], stof(strs[4]),
                                    strs[6], stoi(strs[0]));
      else if (strs[5] == "研究生")
        log = new Graduate_Log(strs[1], strs[2], strs[3], stof(strs[4]),
                               strs[6], stoi(strs[0]));
      logs.push_back(log);
    } else break;
  }
  file.close();
  int choose;
  cout << "欢迎登陆学生成绩管理系统" << endl;
  cout << "输入 1 查看成绩 2 添加成绩 3 删除成绩 4 修改成绩 9 退出系统" << endl;
  cin >> choose;
  while (choose != 9) {
    switch (choose) {
      case 1: view(); break;
      case 2: add(); break;
      case 3: del(); break;
      case 4: change(); break;
      default: cout << "输入错误" << endl; break;
    }
    cin.sync();
    cout << "输入 1 查看成绩 2 添加成绩 3 删除成绩 4 修改成绩 9 退出系统"
         << endl;
    cin >> choose;
  }

  return 0;
}
