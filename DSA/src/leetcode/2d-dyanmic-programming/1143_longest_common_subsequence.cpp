/*
Problem:
Given two strings text1 and text2, return the length of their longest common
subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative order
of the remaining characters.

For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both 
strings.

---
Solution:
We can do the brute force way and check every subsequence from both stings and
find the largest one. This approach would take O(2^L) where L = m + n since we
are checking all combinations of both strings.

A better solution would be to use a dynamic algorithm to check the largest found
subsequence and store it in a 2D table. Basically for each character we keep track
of the previously found largest subsequence and store the maximum value found so far.

This would take O(n*m) for both time and space complexity since we are creating a 2D
array to store the results found so far.

We can further improve the solution by using two arrays instead of a 2D array since 
we only need the most recent computed longest subsequence. This would reduce the 
space complexity to O(min(N,M)).

We can further improve by ensuring we use the smaller string for our previous and
current arrays.
*/

#include "pch.h"

int Solution::longestCommonSubsequence(std::string text1, std::string text2) {

  // pick the smaller string
  if (text1.length() < text2.length())
    std::swap(text1, text2);

  long long int rows = text1.length(), cols = text2.length();
  std::vector<int> previous(cols + 1, 0), current(cols + 1, 0);

  for (long long int i = 1; i <= rows; i++) {
    for (long long int j = 1; j <= cols; j++) {
      if (tolower(text1[i - 1]) == tolower(text2[j - 1])) {
        current[j] = previous[j - 1] + 1;
      }
      else {
        current[j] = std::max(previous[j], current[j - 1]);
      }
    }
    std::swap(current, previous);
  }
  return previous[cols]; // note the last swap
}