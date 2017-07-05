#ifndef INSERVICE
#define INSERVICE
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;
class Person {
  private:
    string name;
    int sex;
  public:
    Person(string _name, int _sex): name(_name), sex(_sex) {
      cout << "Construct Person" << endl;
    }
    ~Person() {
      cout << "Destruct Person" << endl;
    }
    string getName() {
      return name;
    }
    int getSex() {
      return sex;
    }
};
class Student: virtual public Person {
  private:
    string id;
  public:
    Student(string _name, int _sex, string sno): id(sno), Person(_name, _sex) {
      cout << "Construct Student" << endl;
    }
    ~Student() {
      cout << "Destruct Student" << endl;
    }
    string getSno() {
      return id;
    } 
};
class Worker: virtual public Person {
  private:
    string id;
  public:
    Worker(string _name, int _sex, string wno): id(wno), Person(_name, _sex) {
      cout << "Construct Worker" << endl;
    }
    ~Worker() {
      cout << "Destruct Worker" << endl;
    }
    string getWno() {
      return id;
    }
};
class InService: public Student, public Worker {
  public:
    InService(string _name, int _sex, string sno, string wno):
             Student(_name, _sex, sno), Worker(_name, _sex, wno), Person(_name, _sex) {
      cout << "Construct InService" << endl;
    }
    ~InService() {
      cout << "Destruct InService" << endl;
    }
};
#endif