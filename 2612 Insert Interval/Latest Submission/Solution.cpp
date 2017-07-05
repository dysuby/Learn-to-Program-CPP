#include "Solution.hpp"

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  if (intervals.size() == 0) {
    intervals.push_back(newInterval);
    return intervals;
  }
  Interval res;
  bool flag(false);
  if (newInterval.start < intervals[0].start ||
      (newInterval.start >= intervals[0].start 
        && newInterval.start <= intervals[0].end)) {
    flag = true;
    res.start = (newInterval.start <= intervals[0].start) ?
                  newInterval.start : intervals[0].start;
    intervals.erase(intervals.begin());
  }
  auto prev = intervals.begin();
  for (auto i = intervals.begin() + 1; i != intervals.end(); ) {
    if (!flag && (newInterval.start <= i -> start 
          && newInterval.start >= prev -> end) || 
        (newInterval.start >= i -> start 
          && newInterval.start <= i -> end)) {
      flag = true;
      res.start = (newInterval.start <= i -> start) ? 
                  newInterval.start : i -> start;
      if (newInterval.end < i -> start) {
        break;
      }
    }
    if (flag && (
        (newInterval.end <= i -> start 
          && newInterval.end >= prev -> end) || 
        (newInterval.end >= i -> start 
          && newInterval.end <= i -> end))) {
      if (newInterval.end < i -> start) 
        break;
      flag = false;
      res.end = (newInterval.end >= i -> end) ?
                newInterval.end : i -> end;
      intervals.erase(i);
      break;
    } else if (flag) {
      intervals.erase(i);
    } else {
      ++prev; 
      ++i;     
    }
  }
  if (flag) {
    if (intervals.size() != 1) {
      res.end = newInterval.end;
    }
    else if (newInterval.start <= intervals[0].start) {
      res.end = newInterval.end;
    }
    else if (newInterval.start <= intervals[0].end) {
      res.end = intervals[0].end;
      intervals.erase(intervals.begin());
    } else {
      res.end = newInterval.end;
      intervals.erase(intervals.begin());
    }
  }
  for (auto k = intervals.begin(); k != intervals.end(); ++k) {
    if (res.start < k -> start) {
      intervals.insert(k, res);
      flag = true;
      break;
    }
  }
  if (!flag)
    intervals.push_back(res);
  return intervals;
}