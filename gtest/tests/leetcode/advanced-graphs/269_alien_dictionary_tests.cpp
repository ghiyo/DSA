#include "pch.h"

class AlienDictionaryTests : public ::testing::TestWithParam<std::pair<std::vector<std::string>, std::string>> {
protected:
  Solution solution;
};

TEST_P(AlienDictionaryTests, CheckAlienDictionaryOrdering) {
  std::vector<std::string> input = GetParam().first;
  std::string expectedOutcome = GetParam().second;
  EXPECT_EQ(expectedOutcome, solution.alienOrder(input));
}

INSTANTIATE_TEST_CASE_P(Default, AlienDictionaryTests,
  ::testing::Values(
    std::make_pair(std::vector<std::string>{"wrt", "wrf", "er", "ett", "rftt"}, "wertf"),
    std::make_pair(std::vector<std::string>{"z", "x"}, "zx"),
    std::make_pair(std::vector<std::string>{"x", "z", "x"}, ""),
    std::make_pair(std::vector<std::string>{"abc", "ab"}, "")
  ),
);