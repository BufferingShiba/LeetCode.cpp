#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/flood-fill.h"

namespace leetcode::problem_733 {

class FloodFillTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FloodFillSolution solution_;
};

TEST_P(FloodFillTest, Example1) {
  std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  std::vector<std::vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
  EXPECT_EQ(solution_.floodFill(image, 1, 1, 2), expected);
}

TEST_P(FloodFillTest, Example2) {
  std::vector<std::vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
  std::vector<std::vector<int>> expected = {{0, 0, 0}, {0, 0, 0}};
  EXPECT_EQ(solution_.floodFill(image, 0, 0, 0), expected);
}

TEST_P(FloodFillTest, SelfAuthoredSinglePixel) {
  std::vector<std::vector<int>> image = {{1}};
  std::vector<std::vector<int>> expected = {{5}};
  EXPECT_EQ(solution_.floodFill(image, 0, 0, 5), expected);
}

INSTANTIATE_TEST_SUITE_P(FloodFillParam, FloodFillTest,
                         ::testing::ValuesIn(FloodFillSolution().getStrategyNames()));

}  // namespace leetcode::problem_733
