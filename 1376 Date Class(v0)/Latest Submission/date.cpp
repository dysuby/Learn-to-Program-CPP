#include "date.hpp"
using namespace std;
void Date::setDate(int year, int month, int day) {
  year_ = year;
  month_ = month;
  day_ = day;
}
int Date::year() const {
  return year_;
}
int Date::month() const {
  return month_;
}
int Date::day() const {
  return day_;
}
int Date::daysOfMonth(int year, int month) const {
  switch(month) {
    case 2:
      if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 29;
      else 
        return 28;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    default:
      return 31;
  }
}
void Date::increment() {
  int last_day = daysOfMonth(year_, month_);
  if (last_day == day_) {
    if (month_ == 12) {
      month_ = 1;
      day_ = 1;
      ++year_;
    } else {
      ++month_;
      day_ = 1;
    }
  } else {
    ++day_;
  }
}
void Date::decrement() {
  if (month_ == 1 && day_ == 1) {
    month_ = 12;
    day_ = 31;
    --year_;
  } else {
    int last_day = daysOfMonth(year_, month_ - 1);
    if (day_ == 1) {
      day_ = last_day;
      --month_;
    } else {
      --day_;
    }
  }
}