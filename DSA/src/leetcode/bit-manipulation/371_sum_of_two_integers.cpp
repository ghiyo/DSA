/*
Problem:
Given two integers a and b, return the sum of the two integers 
without using the operators + and -.

Solution:
We can use the and operator to find which bit is going to have
a carry and then we shift the bit to the right and store it in
a temporary variable as our carry variable. We then use the XOR
operator between the two numbers to add them together, however
we still need to apply the carry to the numbers, so we set one
of the numbers to be the carry. We loop this until there is no
carry left.

NOTE: This solution is language specific! In Python since the 
numbers have technically infinite bits, it is a bit tricker and
requires some work arounds.
*/

#include "pch.h"


int Solution::getSum(int a, int b) {
  int carry;
  while (b) {
    carry = (b & a) << 1;
    a = (b ^ a);
    b = carry;
  }
  return a;
}