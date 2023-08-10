#include "pch.h"

class ValidPalindromeTest : public ::testing::TestWithParam<std::pair<std::string, bool>> {
protected:
  Solution solution;
};

TEST_P(ValidPalindromeTest, CheckForDuplicates) {
  std::string input = GetParam().first;
  bool expectedOutcome = GetParam().second;
  EXPECT_EQ(expectedOutcome, solution.isPalindrome(input));
}

INSTANTIATE_TEST_CASE_P(Default, ValidPalindromeTest,
  ::testing::Values(
    std::make_pair("A man, a plan, a canal: Panama", true),
    std::make_pair("race a car", false),
    std::make_pair(" ", true)
  ),
);