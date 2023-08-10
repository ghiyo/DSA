/*
Problem:

Given an integer array nums, return true if any value appears at least twice
in the array, and return false if every element is distinct.

---
Solution:

We can use a set to store all the numbers we have seen and for any number we
check the set. If it is there, then it means there is a duplicate.

Runtime complexity is O(n) and space time complexity is O(n) as well since 
we iterate and store at max n times.

*/


#include "pch.h"

bool Solution::containsDuplicate(std::vector<int>& nums) {
  std::unordered_set<int> seen;
  for (int &num : nums) {
    if (seen.count(num)) {
      return true;
    }
    seen.emplace(num);
  }
  return false;
}