#include "date.hpp"
Date::Date() {
  year = 2017;
  month = 1;
  day = 28;
}
Date::Date(int year, int month, int day) {
  setDate(year, month, day);
}
bool Date::equals(const Date otherDate) const {
  if (otherDate.year == year) {
    if (otherDate.month == month) {
      if (otherDate.day == day) {
        return true;
      }
    }
  }
  return false;
}
bool Date::smallerThan(const Date otherDate) const {
  if (otherDate.year < year) {
    return false;
  } else if (otherDate.year == year) {
    if (otherDate.month < month) {
      return false;
    } else if (otherDate.month == month) {
      if (otherDate.day < day) {
        return false;
      }
    }
  }
  return true;
}
void Date::normalize() {
  if (month > 12) {
    month -= 12;
    ++year;
    normalize();
  }
  if (day > daysOfMonth(year, month)) {
    day -= daysOfMonth(year, month);
    ++month;
    normalize();
  }
}