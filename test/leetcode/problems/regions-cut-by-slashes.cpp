#include "leetcode/problems/regions-cut-by-slashes.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_959 {

class RegionsCutBySlashesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  RegionsCutBySlashesSolution solution_;
};

TEST_P(RegionsCutBySlashesTest, Example1) {
  std::vector<std::string> grid = {" /", "/ "};
  EXPECT_EQ(solution_.regionsBySlashes(grid), 2);
}

TEST_P(RegionsCutBySlashesTest, Example2) {
  std::vector<std::string> grid = {" /", "  "};
  EXPECT_EQ(solution_.regionsBySlashes(grid), 1);
}

TEST_P(RegionsCutBySlashesTest, Example3) {
  std::vector<std::string> grid = {"/\\", "\\/"};
  EXPECT_EQ(solution_.regionsBySlashes(grid), 5);
}

TEST_P(RegionsCutBySlashesTest, SelfAuthoredSingleSpace) {
  std::vector<std::string> grid = {" "};
  EXPECT_EQ(solution_.regionsBySlashes(grid), 1);
}

TEST_P(RegionsCutBySlashesTest, SelfAuthoredSingleSlash) {
  std::vector<std::string> grid = {"/"};
  EXPECT_EQ(solution_.regionsBySlashes(grid), 2);
}

TEST_P(RegionsCutBySlashesTest, SelfAuthoredSingleBackslash) {
  std::vector<std::string> grid = {"\\"};
  EXPECT_EQ(solution_.regionsBySlashes(grid), 2);
}

TEST_P(RegionsCutBySlashesTest, SelfAuthoredTwoAdjacentSlash) {
  std::vector<std::string> grid = {"//", "//"};
  // 2x2 grid of forward slashes: each '/' splits its cell diagonally; the
  // scaled 3x3 flood-fill model yields exactly 4 separated empty regions.
  EXPECT_EQ(solution_.regionsBySlashes(grid), 4);
}

INSTANTIATE_TEST_SUITE_P(
    RegionsCutBySlashesTestCases, RegionsCutBySlashesTest,
    ::testing::ValuesIn(RegionsCutBySlashesSolution().getStrategyNames()));

}  // namespace problem_959
}  // namespace leetcode
