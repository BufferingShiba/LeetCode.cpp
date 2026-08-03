#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-capacity-box.h"

namespace leetcode {
namespace problem_3861 {

class MinimumCapacityBoxTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCapacityBoxSolution solution;
};

TEST_P(MinimumCapacityBoxTest, Example1) {
  std::vector<int> capacity = {1, 5, 3, 7};
  EXPECT_EQ(2, solution.minimumIndex(capacity, 3));
}

TEST_P(MinimumCapacityBoxTest, Example2) {
  std::vector<int> capacity = {3, 5, 4, 3};
  EXPECT_EQ(0, solution.minimumIndex(capacity, 2));
}

TEST_P(MinimumCapacityBoxTest, Example3) {
  std::vector<int> capacity = {4};
  EXPECT_EQ(-1, solution.minimumIndex(capacity, 5));
}

TEST_P(MinimumCapacityBoxTest, SelfAuthoredFirstFitTie) {
  std::vector<int> capacity = {5, 5, 5};
  EXPECT_EQ(0, solution.minimumIndex(capacity, 5));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCapacityBoxTestSuite, MinimumCapacityBoxTest,
    ::testing::ValuesIn(MinimumCapacityBoxSolution().getStrategyNames()));

}  // namespace problem_3861
}  // namespace leetcode
