#include <gtest/gtest.h>
#include <vector>

#include "leetcode/problems/construct-uniform-parity-array-i.h"

namespace leetcode::problem_3875 {

class ConstructUniformParityArrayITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ConstructUniformParityArrayISolution solution;
};

TEST_P(ConstructUniformParityArrayITest, Example1) {
  std::vector<int> nums1{2, 3};
  EXPECT_TRUE(solution.uniformArray(nums1));
}

TEST_P(ConstructUniformParityArrayITest, Example2) {
  std::vector<int> nums1{4, 6};
  EXPECT_TRUE(solution.uniformArray(nums1));
}

TEST_P(ConstructUniformParityArrayITest, SingleOddElement) {
  std::vector<int> nums1{7};
  EXPECT_TRUE(solution.uniformArray(nums1));
}

TEST_P(ConstructUniformParityArrayITest, SingleEvenElement) {
  std::vector<int> nums1{10};
  EXPECT_TRUE(solution.uniformArray(nums1));
}

TEST_P(ConstructUniformParityArrayITest, PluralOddsWithAnEven) {
  std::vector<int> nums1{3, 5, 2};
  EXPECT_TRUE(solution.uniformArray(nums1));
}

INSTANTIATE_TEST_SUITE_P(
    ConstructUniformParityArrayITests, ConstructUniformParityArrayITest,
    ::testing::ValuesIn(
        ConstructUniformParityArrayISolution().getStrategyNames()));

}  // namespace leetcode::problem_3875
