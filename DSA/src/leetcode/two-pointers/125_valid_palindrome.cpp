/*
Problem:

A phrase is a palindrome if, after converting all uppercase letters 
into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include 
letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

---
Solution:

We can keep track of 2 pointers on each end of the string and move them
closer to the center one step at a time and if at any point the letters
do not match, we know that it is not a valid palindrome.

*/

#include "pch.h"

bool Solution::isPalindrome(std::string s) {
  return false;
}