#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/construct-uniform-parity-array-ii.h"

namespace leetcode {
namespace problem_3876 {
namespace {

class ConstructUniformParityArrayIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConstructUniformParityArrayIiSolution solution_;
};

TEST_P(ConstructUniformParityArrayIiTest, Example1) {
  std::vector<int> nums{1, 4, 7};
  EXPECT_TRUE(solution_.uniformArray(nums));
}

TEST_P(ConstructUniformParityArrayIiTest, Example2) {
  std::vector<int> nums{2, 3};
  EXPECT_FALSE(solution_.uniformArray(nums));
}

TEST_P(ConstructUniformParityArrayIiTest, Example3) {
  std::vector<int> nums{4, 6};
  EXPECT_TRUE(solution_.uniformArray(nums));
}

TEST_P(ConstructUniformParityArrayIiTest, SelfAuthoredSingleOddElement) {
  std::vector<int> nums{5};
  EXPECT_TRUE(solution_.uniformArray(nums));
}

TEST_P(ConstructUniformParityArrayIiTest, SelfAuthoredSingleEvenElement) {
  std::vector<int> nums{8};
  EXPECT_TRUE(solution_.uniformArray(nums));
}

TEST_P(ConstructUniformParityArrayIiTest, SelfAuthoredOddThenEvenOnly) {
  // sorted: [2,5]; target odd needs even element with smaller odd prev -> fail
  std::vector<int> nums{2, 5};
  EXPECT_FALSE(solution_.uniformArray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    ConstructUniformParityArrayIiTests, ConstructUniformParityArrayIiTest,
    ::testing::ValuesIn(ConstructUniformParityArrayIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3876
}  // namespace leetcode
