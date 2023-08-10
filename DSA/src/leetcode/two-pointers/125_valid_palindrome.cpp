/*
Problem:

A phrase is a palindrome if, after converting all uppercase letters 
into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include 
letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Note that the string may have non-alphanumeric characters which should be ignored.

---
Solution:

We can keep track of 2 pointers on each end of the string and move them
closer to the center one step at a time and if at any point the letters
do not match, we know that it is not a valid palindrome.

If either pointer sees a non-alphanumeric character, we will just ignore it and
move to the next pointer.

*/

#include "pch.h"

bool Solution::isPalindrome(std::string s) {
  int i = 0, j = (int)(s.length() - 1);
  while (i < j) {
    if (isalnum(s[i]) && isalnum(s[j])) {
      if (tolower(s[i]) != tolower(s[j]))
        return false;
      i++;
      j--;
    } else {
      if (!isalnum(s[i]))
        i++;
      if (!isalnum(s[j]))
        j--;
    }
  }
  return true;
}