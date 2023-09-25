#include "pch.h"

class LongestCommonSubsequenceTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, int>> {
protected:
  Solution solution;
};

TEST_P(LongestCommonSubsequenceTest, CheckForLongestCommonSubsequence) {
  std::string text1 = std::get<0>(GetParam());
  std::string text2 = std::get<1>(GetParam());
  int expectedOutcome = std::get<2>(GetParam());
  EXPECT_EQ(expectedOutcome, solution.longestCommonSubsequence(text1, text2));
}

INSTANTIATE_TEST_CASE_P(Default, LongestCommonSubsequenceTest,
  ::testing::Values(
    std::make_tuple("abcde", "ace", 3),
    std::make_tuple("abc", "abc", 3),
    std::make_tuple("abc", "def", 0),
    std::make_tuple("abcdegf", "eabcd", 4),
    std::make_tuple("eabcda", "abbcdefgaab", 5)
  ),
);