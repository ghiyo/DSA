#include "pch.h"

class ContainsDuplicateTest : public ::testing::TestWithParam<std::pair<std::vector<int>, bool>> {
protected:
  Solution solution;
};

TEST_P(ContainsDuplicateTest, CheckForDuplicates) {
  std::vector<int> input = GetParam().first;
  bool expectedOutcome = GetParam().second;
  EXPECT_EQ(expectedOutcome, solution.containsDuplicate(input));
}

INSTANTIATE_TEST_CASE_P(Default, ContainsDuplicateTest,
  ::testing::Values(
    std::make_pair(std::vector<int>{1, 2, 3, 1}, true),
    std::make_pair(std::vector<int>{1, 2, 3, 4}, false),
    std::make_pair(std::vector<int>{1,1,1,3,3,4,3,2,4,2}, true),
    std::make_pair(std::vector<int>{}, false)
  ),
);