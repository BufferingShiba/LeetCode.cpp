#include "leetcode/problems/minimum-operations-to-make-array-modulo-alternating-i.h"

#include <gtest/gtest.h>

namespace leetcode::problem_3937 {

class MinimumOperationsToMakeArrayModuloAlternatingITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumOperationsToMakeArrayModuloAlternatingISolution solution;
};

TEST_P(MinimumOperationsToMakeArrayModuloAlternatingITest, Example1) {
  std::vector<int> nums{1, 4, 2, 8};
  int k = 3;
  EXPECT_EQ(solution.minOperations(nums, k), 2);
}

TEST_P(MinimumOperationsToMakeArrayModuloAlternatingITest, Example2) {
  std::vector<int> nums{1, 1, 1};
  int k = 3;
  EXPECT_EQ(solution.minOperations(nums, k), 1);
}

TEST_P(MinimumOperationsToMakeArrayModuloAlternatingITest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  int k = 2;
  // 只有一个元素，只需匹配 x，y 可任意取不同值不产生成本。最优为 0（保持原样）。
  EXPECT_EQ(solution.minOperations(nums, k), 0);
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(MinimumOperationsToMakeArrayModuloAlternatingITest, WrongAnswerCase1) {
  // 输入: nums = [78,339182,56,83568], k = 8
    // 期望: 4
    std::vector<int> nums{78, 339182, 56, 83568};
    int k = 8;
    EXPECT_EQ(solution.minOperations(nums, k), 4);
}
INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToMakeArrayModuloAlternatingITestSuite,
    MinimumOperationsToMakeArrayModuloAlternatingITest,
    ::testing::ValuesIn(MinimumOperationsToMakeArrayModuloAlternatingISolution().getStrategyNames()));

}  // namespace leetcode::problem_3937
