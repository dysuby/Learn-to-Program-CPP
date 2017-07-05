 #ifndef DATE_H
#define DATE_H
#include <string>
#include <sstream>
using std::istringstream;
using std::ostringstream;
using std::string;

class Date {
  private:
    int _year;
    int _month;
    int _day;
  public:
    Date(int y, int m, int d): _year(y), _month(m), _day(d) {}
    Date(string dateString) {
      istringstream in(dateString);
      in >> _year;
      char temp = '\0';
      in >> temp;
      in >> _month;
      in >> temp;
      in >> _day;
    }
    int getYear() const {
      return _year;
    }
    void setYear(int y) {
      _year = y;
    }
    int getMonth() const {
      return _month;
    }
    void setMonth(int m) {
      _month = m;
    }
    int getDay() const {
      return _day;
    }
    void setDay(int d) {
      _day = d;
    }
    bool operator==(Date& other) const {
      return (_year == other._year) && (_month == other. _month) &&
              (_day == other._day);
    }
    bool operator<(Date& other) const {
      if (_year < other._year) {
        return true;
      } else if (_year == other._year && _month < other._month) {
        return true;
      } else if (_year == other._year && _month == other._month && 
                  _day < other._day) {
        return true;
      } else {
        return false;
      }
    }
    bool operator>(Date& other) const {
      return !(*this == other || *this < other);
    }
    std::string toString() const {
      ostringstream out;
      out << _year << "-" << _month << "-" << _day;
      return out.str();
    }
};

#endif