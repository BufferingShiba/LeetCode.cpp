#include <gtest/gtest.h>

#include "leetcode/problems/array-partition.h"
#include <vector>
#include <string>

namespace leetcode {
namespace problem_561 {

class ArrayPartitionTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  ArrayPartitionSolution solution;
};

TEST_P(ArrayPartitionTest, Example1) {
  std::vector<int> nums = {1, 4, 3, 2};
  EXPECT_EQ(4, solution.arrayPairSum(nums));
}

TEST_P(ArrayPartitionTest, Example2) {
  std::vector<int> nums = {6, 2, 6, 5, 1, 2};
  EXPECT_EQ(9, solution.arrayPairSum(nums));
}

TEST_P(ArrayPartitionTest, SelfAuthoredSinglePairSameValues) {
  std::vector<int> nums = {5, 5};
  EXPECT_EQ(5, solution.arrayPairSum(nums));
}

TEST_P(ArrayPartitionTest, SelfAuthoredSinglePairDifferentValues) {
  std::vector<int> nums = {-3, 7};
  EXPECT_EQ(-3, solution.arrayPairSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    ArrayPartitionStrategies,
    ArrayPartitionTest,
    ::testing::ValuesIn(ArrayPartitionSolution().getStrategyNames()));

}  // namespace problem_561
}  // namespace leetcode
