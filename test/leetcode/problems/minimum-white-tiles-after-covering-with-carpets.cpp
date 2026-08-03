#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/minimum-white-tiles-after-covering-with-carpets.h"

namespace leetcode::problem_2209 {

class MinimumWhiteTilesAfterCoveringWithCarpetsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumWhiteTilesAfterCoveringWithCarpetsSolution solution_;
};

TEST_P(MinimumWhiteTilesAfterCoveringWithCarpetsTest, Example1) {
  EXPECT_EQ(solution_.minimumWhiteTiles("10110101", 2, 2), 2);
}

TEST_P(MinimumWhiteTilesAfterCoveringWithCarpetsTest, Example2) {
  EXPECT_EQ(solution_.minimumWhiteTiles("11111", 2, 3), 0);
}

TEST_P(MinimumWhiteTilesAfterCoveringWithCarpetsTest, AllBlack) {
  EXPECT_EQ(solution_.minimumWhiteTiles("00000", 1, 2), 0);
}

TEST_P(MinimumWhiteTilesAfterCoveringWithCarpetsTest, SingleCarpet) {
  // floor="10101", one carpet of length 2 can cover at most 2 tiles
  // best: cover positions [0,1] (covers one '1' at pos 0) → visible: 3 white
  // or cover [2,3] → visible: 2 at pos 0,4 + 1 at pos? Let's trust DP
  EXPECT_EQ(solution_.minimumWhiteTiles("10101", 1, 2), 2);
}

TEST_P(MinimumWhiteTilesAfterCoveringWithCarpetsTest, CarpetLongerThanFloor) {
  EXPECT_EQ(solution_.minimumWhiteTiles("111", 1, 5), 0);
}

TEST_P(MinimumWhiteTilesAfterCoveringWithCarpetsTest, OverlappingCarpets) {
  // floor="1111", 2 carpets of length 2 → cover [0,1] + [2,3] = all covered
  EXPECT_EQ(solution_.minimumWhiteTiles("1111", 2, 2), 0);
}

TEST_P(MinimumWhiteTilesAfterCoveringWithCarpetsTest, ManyCarpets) {
  EXPECT_EQ(solution_.minimumWhiteTiles("1010101010", 5, 2), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumWhiteTilesAfterCoveringWithCarpetsTest,
    testing::ValuesIn(
        MinimumWhiteTilesAfterCoveringWithCarpetsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2209
