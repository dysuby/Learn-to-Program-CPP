 #include "date.hpp"

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

void Date::increase() {
  int total = daysOfMonth(year_, month_);
  if (day_ == total && month_ != 12) {
    day_ = 1;
    ++month_;
  } else if (day_ == total && month_ == 12) {
    day_ = 1;
    month_ = 1;
    ++year_;
  } else {
    ++day_;
  }
}
void Date::decrease() {
  if (day_ == 1 && month_ != 1) {
    --month_;
    day_ = daysOfMonth(year_, month_);
  } else if (day_ == 1 && month_ == 1) {
    month_ = 12;
    day_ = 31;
    --year_;
  } else {
    --day_;
  }
}
int Date::daysOfMonth(int year, int month) const {
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0))
    return 29;
  return days[month - 1];
}
