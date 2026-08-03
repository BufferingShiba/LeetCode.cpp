#include <gtest/gtest.h>

#include "leetcode/problems/flipping-an-image.h"

namespace leetcode {
namespace problem_832 {

class FlippingAnImageTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  FlippingAnImageSolution solution;
};

TEST_P(FlippingAnImageTest, Example1) {
  std::vector<std::vector<int>> image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
  std::vector<std::vector<int>> expected = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  EXPECT_EQ(solution.flipAndInvertImage(image), expected);
}

TEST_P(FlippingAnImageTest, Example2) {
  std::vector<std::vector<int>> image = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
  std::vector<std::vector<int>> expected = {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}};
  EXPECT_EQ(solution.flipAndInvertImage(image), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FlippingAnImageTest,
    ::testing::ValuesIn(FlippingAnImageSolution().getStrategyNames()));

}  // namespace problem_832
}  // namespace leetcode
