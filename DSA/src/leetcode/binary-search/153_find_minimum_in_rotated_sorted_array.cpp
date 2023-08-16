/*
Problem:
Suppose an array of length n sorted in ascending order is 
rotated between 1 and n times. For example, the array 
nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 
1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return 
the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Solution:
We can do a binary search and compare the low, middle, and high elements 
with our current minimum. If any of them are lower, we save that number.
Next we check to see which half is sorted properly. i.e. if middle > low
then we know that left side is sorted properly and the only possible minimum
value would be whatever value that is stored at low. 

On the other hand if right hand side is sorted properly then we know that 
no value will be lower than the middle value. We will have to do a binary 
search again on the side that is not sorted to find potential lower minimums. 
We will repeat the process until our low is equal to our high.

Running time complexity would be O(logn) since we are cutting our problem by half
each time.
*/

#include "pch.h"

int Solution::findMin(std::vector<int>& nums) {
  int low = 0, high = nums.size() - 1, mid, minimum = nums[low]; // we are guaranteed nums is never empty
  while (low <= high) {
    mid = (low + high) / 2;
    if (nums[low] <= nums[mid] && nums[mid] <= nums[high]) { // both sides are sorted, check low and break
      if (nums[low] < minimum)
        minimum = nums[low];
      break;
    }
    if (nums[low] <= nums[mid]) { // left side is sorted, check for new minimum and search right side
      if (nums[low] < minimum)
        minimum = nums[low];
      low = mid + 1;
    }
    if (nums[mid] <= nums[high]) { // right side is sortedm check for new minimum and search left side
      if (nums[mid] < minimum)
        minimum = nums[mid];
      high = mid - 1;
    }
  }
  return minimum;
}