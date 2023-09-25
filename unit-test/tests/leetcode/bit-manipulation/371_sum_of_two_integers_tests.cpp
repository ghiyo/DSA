#include "pch.h"

class SumOfTwoIntegersTests : public ::testing::TestWithParam<std::tuple<int, int, int>> {
protected:
  Solution solution;
};

TEST_P(SumOfTwoIntegersTests, CheckSumOfTwoIntegers) {
  int num1 = std::get<0>(GetParam());
  int num2 = std::get<1>(GetParam());
  int expectedOutcome = std::get<2>(GetParam());
  EXPECT_EQ(expectedOutcome, solution.getSum(num1, num2));
}

INSTANTIATE_TEST_CASE_P(Default, SumOfTwoIntegersTests,
  ::testing::Values(
    std::make_tuple(1, 2, 3),
    std::make_tuple(1, -2, -1),
    std::make_tuple(2, -1, 1),
    std::make_tuple(2, 0, 2),
    std::make_tuple(1, 1, 2),
    std::make_tuple(-1, 0, -1),
    std::make_tuple(0, 0, 0)

  ),
);