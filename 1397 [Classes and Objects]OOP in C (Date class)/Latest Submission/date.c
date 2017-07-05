#include "date.h"
#include <stdlib.h>
#include <stdio.h>
Date* CreateDate(int year, int month, int day) {
  Date* newDate = (Date*)malloc(sizeof(Date));
  newDate -> year = year;
  newDate -> month = month;
  newDate -> day = day;
  return newDate;
}
void DestroyDate(Date** p) {
  free(*p);
  *p = NULL;
}
Date* CopyDate(const Date* date) {
  Date* copyDate = (Date*)malloc(sizeof(Date));
  *copyDate = *date;
}

int GetYear(const Date* date) {
  return date -> year;
}
int GetMonth(const Date* date) {
  return date -> month;
}
int GetDay(const Date* date) {
  return date -> day;
}
void SetYear(Date* date, int year) {
  date -> year = year;
}
void SetMonth(Date* date, int month) {
  date -> month = month;
}
void SetDay(Date* date, int day) {
  date -> day = day;
}
void SetDate(Date* date, int year, int month, int day) {
  date -> year = year;
  date -> month = month;
  date -> day = day;
}

char* GetDateString(const Date* date) {
  char* str = (char*)malloc(11 * sizeof(char));
  sprintf(str, "%04d-%02d-%02d", date -> year, date -> month, date -> day);
  return str;
}
void DestroyDateString(char** p) {
  free(*p);
  *p = NULL;
}
int daysOfMonth(int year, int month) {
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
void IncreaseDate(Date* date) {
  int last_day = daysOfMonth(date -> year, date -> month);
  if (last_day == date -> day) {
    if (date -> month == 12) {
      date -> month = 1;
      date -> day = 1;
      ++date -> year;
    } else {
      ++date -> month;
      date -> day = 1;
    }
  } else {
    ++date -> day;
  }
}
void DecreaseDate(Date* date) {
  if (date -> month == 1 && date -> day == 1) {
    date -> month = 12;
    date -> day = 31;
    --date -> year;
  } else {
    int last_day = daysOfMonth(date -> year, date -> month - 1);
    if (date -> day == 1) {
      date -> day = last_day;
      --date -> month;
    } else {
      --date -> day;
    }
  }
}