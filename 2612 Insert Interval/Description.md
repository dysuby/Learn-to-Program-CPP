# Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

### Example 1:
#### Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

### Example 2:
#### Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

中文大意：
	给出一连串不重叠的区间，再给出一个新的区间，把这个新区间插入到一连串的区间中去，有重叠时则进行合并操作