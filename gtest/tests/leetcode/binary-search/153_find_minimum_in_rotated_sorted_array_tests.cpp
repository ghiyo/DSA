#include "pch.h"

class MinimumInSortedCircularArrayTests : public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {
protected:
  Solution solution;
};

TEST_P(MinimumInSortedCircularArrayTests, CheckMinimumInSortedCircularArray) {
  std::vector<int> nums = std::get<0>(GetParam());
  int expectedOutcome = std::get<1>(GetParam());
  EXPECT_EQ(expectedOutcome, solution.findMin(nums));
}

INSTANTIATE_TEST_CASE_P(Default, MinimumInSortedCircularArrayTests,
  ::testing::Values(
    std::make_tuple(std::vector<int>{3, 4, 5, 1, 2}, 1),
    std::make_tuple(std::vector<int>{3, 4, 5, 6, 2}, 2),
    std::make_tuple(std::vector<int>{4, 5, 6, 7, 0, 1, 2}, 0),
    std::make_tuple(std::vector<int>{11, 13, 15, 17}, 11),
    std::make_tuple(std::vector<int>{1}, 1)
  ),
);