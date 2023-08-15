#include "pch.h"

class CombinationSumTests : public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<std::vector<int>>>> {
protected:
  Solution solution;
};

TEST_P(CombinationSumTests, CheckCombinationSums) {
  std::vector<int> candidates = std::get<0>(GetParam());
  int target = std::get<1>(GetParam());
  std::vector<std::vector<int>> expectedOutcome = std::get<2>(GetParam());
  EXPECT_EQ(expectedOutcome, solution.combinationSum(candidates, target));
}

INSTANTIATE_TEST_CASE_P(Default, CombinationSumTests,
  ::testing::Values(
    std::make_tuple(std::vector<int>{2, 3, 6, 7}, 7, std::vector<std::vector<int>>{{2, 2, 3}, { 7 }}),
    std::make_tuple(std::vector<int>{2, 3, 5}, 8, std::vector<std::vector<int>>{{2, 2, 2, 2}, { 2, 3, 3 }, { 3, 5 }}),
    std::make_tuple(std::vector<int>{2}, 1, std::vector<std::vector<int>>{})
  ),
);