#include "pch.h"

class LongestPalindromicSubstringTest : public ::testing::TestWithParam<std::pair<std::string, std::string>> {
protected:
  Solution solution;
};

TEST_P(LongestPalindromicSubstringTest, CheckForLongestPalindromicSubstring) {
  std::string input = GetParam().first;
  std::string expectedOutcome = GetParam().second;
  EXPECT_EQ(expectedOutcome, solution.longestPalindrome(input));
}

INSTANTIATE_TEST_CASE_P(Default, LongestPalindromicSubstringTest,
  ::testing::Values(
    std::make_pair("babad", "bab"),
    std::make_pair("cbbd", "bb"),
    std::make_pair("1", "1"),
    std::make_pair("12", "1"),
    std::make_pair("121", "121"),
    std::make_pair("baabad", "baab"),
    std::make_pair("baabbaabad", "baabbaab"),
    std::make_pair("ccc", "ccc"),
    std::make_pair("bb", "bb")
  ),
);