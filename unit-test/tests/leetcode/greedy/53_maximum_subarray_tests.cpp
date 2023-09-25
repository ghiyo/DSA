#include "pch.h"

class MaximumSubarrayTests : public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {
protected:
  Solution solution;
};

TEST_P(MaximumSubarrayTests, CheckMaximumSubarray) {
  std::vector<int> nums = std::get<0>(GetParam());
  int expectedOutcome = std::get<1>(GetParam());
  EXPECT_EQ(expectedOutcome, solution.maxSubArray(nums));
}

INSTANTIATE_TEST_CASE_P(Default, MaximumSubarrayTests,
  ::testing::Values(
    std::make_tuple(std::vector<int>{},0)
  ),
);