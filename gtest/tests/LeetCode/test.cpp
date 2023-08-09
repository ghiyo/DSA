#include "pch.h"
#include "../../../DSA/include/LeetCode.h"

TEST(TestCaseName, TestName) {
  std::vector<int> input{ 1,2,3,4 };
  bool outcome = containsDuplicate(input);
  EXPECT_EQ(false, outcome);
  EXPECT_TRUE(true);
}