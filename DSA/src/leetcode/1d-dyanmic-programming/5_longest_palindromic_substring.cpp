/*
Problem:
Given a string s, return the longest palindromic substring in s.

---
Solution:
The brute force solution is to check every substring in the original
string and find the largest palindrome by keeping track of the largest
one. This solution will take O(n^2) for going through all substrings and 
another O(n) to check if the substring is palindromic, so it would take
O(n^3).


*/

#include "pch.h"

std::string Solution::longestPalindrome(std::string s) {
  long long int res_start = 0, res_length = 0;
  long long int n = s.length();
  for (long long int i = 0; i < n; i++) {
    // odd
    long long int l = i, r = i;
    
    while (l >= 0 && r < n && s[l] == s[r]) {
      if (r - l + 1 > res_length) {
        res_length = r - l + 1;
        res_start = l;
      }
      l--;
      r++;
    }

    // even
    l = i, r = i + 1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      if (r - l + 1 > res_length) {
        res_length = r - l + 1;
        res_start = l;
      }
      l--;
      r++;
    }
  }
  return s.substr(res_start, res_length);
}