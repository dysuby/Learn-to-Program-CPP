 #ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Date.h"

class Student: public Person {
  public:
    Student(string name, int age, Date date): Person(name, age),
                                              graduateDate(date.toString()) {}
    void set(Date d) {
      graduateDate.setYear(d.getYear());
      graduateDate.setMonth(d.getMonth());
      graduateDate.setDay(d.getDay());
    }
    void sayHi() const {
      Person::sayHi();
      Date today("2017-5-7");
      if (graduateDate == today)
        cout << "I graduated today!" << endl;
      else if (graduateDate < today)
        cout << "I have graduated on " << graduateDate.toString() 
              << "." << endl;
      else if (graduateDate > today)
        cout << "I will graduate on " << graduateDate.toString()
              << "." << endl;
    }
    void set(int age) {
      Person::set(age);
    }
    void set(string name) {
      Person::set(name);
    }
  private:
    Date graduateDate;
};
#endif