#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "leetcode/problems/twisted-mirror-path-count.h"

namespace leetcode {
namespace problem_3665 {

class TwistedMirrorPathCountTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  TwistedMirrorPathCountSolution solution_;
};

TEST_P(TwistedMirrorPathCountTest, Example1) {
  std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
  EXPECT_EQ(solution_.uniquePaths(grid), 5);
}

TEST_P(TwistedMirrorPathCountTest, Example2) {
  std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}};
  EXPECT_EQ(solution_.uniquePaths(grid), 2);
}

TEST_P(TwistedMirrorPathCountTest, Example3) {
  std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 0}};
  EXPECT_EQ(solution_.uniquePaths(grid), 1);
}

TEST_P(TwistedMirrorPathCountTest, SelfAuthoredSingleCellGrid) {
  std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}, {0, 0}};
  // 3x2 empty grid, unique paths = C(3,1)=3
  EXPECT_EQ(solution_.uniquePaths(grid), 3);
}

INSTANTIATE_TEST_SUITE_P(
    TwistedMirrorPathCountSuite,
    TwistedMirrorPathCountTest,
    ::testing::ValuesIn(TwistedMirrorPathCountSolution().getStrategyNames()));

}  // namespace problem_3665
}  // namespace leetcode
