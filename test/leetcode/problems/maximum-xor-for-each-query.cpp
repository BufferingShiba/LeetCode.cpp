#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-xor-for-each-query.h"

namespace leetcode::problem_1829 {

class MaximumXorForEachQueryTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  MaximumXorForEachQuerySolution solution;
};

TEST_P(MaximumXorForEachQueryTest, Example1) {
  std::vector<int> nums{0, 1, 1, 3};
  std::vector<int> expected{0, 3, 2, 3};
  EXPECT_EQ(solution.getMaximumXor(nums, 2), expected);
}

TEST_P(MaximumXorForEachQueryTest, Example2) {
  std::vector<int> nums{2, 3, 4, 7};
  std::vector<int> expected{5, 2, 6, 5};
  EXPECT_EQ(solution.getMaximumXor(nums, 3), expected);
}

TEST_P(MaximumXorForEachQueryTest, Example3) {
  std::vector<int> nums{0, 1, 2, 2, 5, 7};
  std::vector<int> expected{4, 3, 6, 4, 6, 7};
  EXPECT_EQ(solution.getMaximumXor(nums, 3), expected);
}

TEST_P(MaximumXorForEachQueryTest, SingleElement) {
  std::vector<int> nums{5};
  std::vector<int> expected{2};  // maxMask=7, curr=5, k=7^5=2
  EXPECT_EQ(solution.getMaximumXor(nums, 3), expected);
}

TEST_P(MaximumXorForEachQueryTest, MaxBitOneBit) {
  std::vector<int> nums{0, 0, 1};
  std::vector<int> expected{0, 1, 1};  // maxMask=1
  EXPECT_EQ(solution.getMaximumXor(nums, 1), expected);
}

INSTANTIATE_TEST_SUITE_P(MaximumXorForEachQueryTests, MaximumXorForEachQueryTest,
                         ::testing::ValuesIn(MaximumXorForEachQuerySolution().getStrategyNames()));

}  // namespace leetcode::problem_1829
