#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-it-is-a-straight-line.h"

namespace leetcode {
namespace problem_1232 {
namespace {

std::vector<std::vector<int>> BuildCoords(
    const std::vector<std::vector<int>>& coords) {
  return coords;
}

}  // namespace

class CheckIfItIsAStraightLineTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution.setStrategy(GetParam()); }

 protected:
  CheckIfItIsAStraightLineSolution solution;
};

TEST_P(CheckIfItIsAStraightLineTest, Example1) {
  auto coordinates = BuildCoords(
      {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}});
  EXPECT_TRUE(solution.checkStraightLine(coordinates));
}

TEST_P(CheckIfItIsAStraightLineTest, Example2) {
  auto coordinates = BuildCoords(
      {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}});
  EXPECT_FALSE(solution.checkStraightLine(coordinates));
}

TEST_P(CheckIfItIsAStraightLineTest, SelfAuthoredVerticalLine) {
  auto coordinates = BuildCoords(
      {{2, -1}, {2, 3}, {2, 5}, {2, 9}});
  EXPECT_TRUE(solution.checkStraightLine(coordinates));
}

TEST_P(CheckIfItIsAStraightLineTest, SelfAuthoredHorizontalLine) {
  auto coordinates = BuildCoords(
      {{-3, 4}, {-1, 4}, {0, 4}, {5, 4}});
  EXPECT_TRUE(solution.checkStraightLine(coordinates));
}

TEST_P(CheckIfItIsAStraightLineTest, SelfAuthoredNonCollinearWithVerticalBase) {
  auto coordinates = BuildCoords(
      {{1, 1}, {1, 5}, {2, 1}});
  EXPECT_FALSE(solution.checkStraightLine(coordinates));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfItIsAStraightLineTestSuite,
    CheckIfItIsAStraightLineTest,
    ::testing::ValuesIn(CheckIfItIsAStraightLineSolution().getStrategyNames()));

}  // namespace problem_1232
}  // namespace leetcode
