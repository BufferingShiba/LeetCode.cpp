#include <gtest/gtest.h>

#include "leetcode/problems/number-of-adjacent-elements-with-the-same-color.h"

namespace leetcode {
namespace problem_2672 {

class NumberOfAdjacentElementsWithTheSameColorTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfAdjacentElementsWithTheSameColorSolution solution_;
};

TEST_P(NumberOfAdjacentElementsWithTheSameColorTest, Example1) {
  int n = 4;
  std::vector<std::vector<int>> queries = {{0, 2}, {1, 2}, {3, 1}, {1, 1}, {2, 1}};
  std::vector<int> expected = {0, 1, 1, 0, 2};
  EXPECT_EQ(solution_.colorTheArray(n, queries), expected);
}

TEST_P(NumberOfAdjacentElementsWithTheSameColorTest, Example2) {
  int n = 1;
  std::vector<std::vector<int>> queries = {{0, 100000}};
  std::vector<int> expected = {0};
  EXPECT_EQ(solution_.colorTheArray(n, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfAdjacentElementsWithTheSameColorTest,
    testing::ValuesIn(
        NumberOfAdjacentElementsWithTheSameColorSolution().getStrategyNames()));

}  // namespace problem_2672
}  // namespace leetcode
