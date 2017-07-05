#include <string>
#include <iostream>
using namespace std;
 
class Person {
  public:
    Person(string name, int sex) : name(name), sex(sex) { 
      cout << "Construct Person" << endl;
    }
    ~Person() { cout << "Destruct Person" << endl;}
    string getName() {
      return name;
    }
    int getSex() {
      return sex;
    }
  private:
    string name;  //  姓名
    int sex;  //  1表示男 0表示女
};
 
class Student: virtual public Person {
  public:
    Student(string name, int sex, string sno) : Person(name, sex), sno(sno) { 
      cout << "Construct Student" << endl;
    }
    ~Student() { cout << "Destruct Student" << endl;}
    string getSno() {
      return sno;
    }
  private:
    string sno;  //  学号
};
 
class Worker: virtual public Person {
  public:
    Worker(string name, int sex, string wno) : Person(name, sex), wno(wno) { 
      cout << "Construct Worker" << endl;
    }
    ~Worker() { cout << "Destruct Worker" << endl;}
    string getWno() {
      return wno;
    }
  private:
    string wno;  //  职工号
};
 
class InService: public Student, public Worker {
  public:
    InService(string name, int sex, string sno, string wno) : 
              Person(name, sex), Student(name, sex, sno), Worker(name, sex, wno) { 
      cout << "Construct InService" << endl;
    }
    ~InService() { cout << "Destruct InService" << endl;}
};