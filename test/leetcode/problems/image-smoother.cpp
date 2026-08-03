#include <gtest/gtest.h>

#include "leetcode/problems/image-smoother.h"

namespace leetcode::problem_661 {

class ImageSmootherTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ImageSmootherSolution solution;
};

TEST_P(ImageSmootherTest, Example1) {
  std::vector<std::vector<int>> img = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  std::vector<std::vector<int>> expected = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  EXPECT_EQ(solution.imageSmoother(img), expected);
}

TEST_P(ImageSmootherTest, Example2) {
  std::vector<std::vector<int>> img = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};
  std::vector<std::vector<int>> expected = {{137, 141, 137}, {141, 138, 141}, {137, 141, 137}};
  EXPECT_EQ(solution.imageSmoother(img), expected);
}

TEST_P(ImageSmootherTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> img = {{42}};
  std::vector<std::vector<int>> expected = {{42}};
  EXPECT_EQ(solution.imageSmoother(img), expected);
}

TEST_P(ImageSmootherTest, SelfAuthoredSingleRow) {
  std::vector<std::vector<int>> img = {{2, 4, 6}};
  // (2+4)/2=3, (2+4+6)/3=4, (4+6)/2=5
  std::vector<std::vector<int>> expected = {{3, 4, 5}};
  EXPECT_EQ(solution.imageSmoother(img), expected);
}

INSTANTIATE_TEST_SUITE_P(, ImageSmootherTest,
                         testing::ValuesIn(ImageSmootherSolution().getStrategyNames()));

}  // namespace leetcode::problem_661
