#include "pch.h"

class PacificAtlanticWaterflowTests : public ::testing::TestWithParam<std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<int>>>> {
protected:
  Solution solution;
};

TEST_P(PacificAtlanticWaterflowTests, CheckPacificAtlanticWaterflow) {
  std::vector<std::vector<int>> grid = std::get<0>(GetParam());
  std::vector<std::vector<int>> expectedOutcome = std::get<1>(GetParam());
  EXPECT_EQ(expectedOutcome, solution.pacificAtlantic(grid));
}

INSTANTIATE_TEST_CASE_P(Default, PacificAtlanticWaterflowTests,
  ::testing::Values(
    std::make_tuple(
      std::vector<std::vector<int>>{
        { 1, 2, 2, 3, 5 },
        { 3, 2, 3, 4, 4 },
        { 2, 4, 5, 3, 1 },
        { 6, 7, 1, 4, 5 },
        { 5, 1, 1, 2, 4 }
      },
      std::vector<std::vector<int>>{
        { 0, 4 },
        { 1, 3 },
        { 1, 4 },
        { 2, 2 },
        { 3, 0 },
        { 3, 1 },
        { 4, 0 },
      }
    ),
    std::make_tuple(
      std::vector<std::vector<int>>{{ 1 }},
      std::vector<std::vector<int>>{{ 0, 0 }}
    ),
    std::make_tuple(
      std::vector<std::vector<int>>{{ 1, 1 }, { 1, 1 }, { 1, 1 }},
      std::vector<std::vector<int>>{{ 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 0 }, { 2, 1 }}
    )
  ),
);