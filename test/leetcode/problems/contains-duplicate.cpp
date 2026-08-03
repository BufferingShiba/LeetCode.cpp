#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/contains-duplicate.h"

namespace leetcode {
namespace problem_217 {

class ContainsDuplicateTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ContainsDuplicateSolution solution_;
};

TEST_P(ContainsDuplicateTest, Example1) {
  std::vector<int> nums{1, 2, 3, 1};
  EXPECT_TRUE(solution_.containsDuplicate(nums));
}

TEST_P(ContainsDuplicateTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4};
  EXPECT_FALSE(solution_.containsDuplicate(nums));
}

TEST_P(ContainsDuplicateTest, Example3) {
  std::vector<int> nums{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  EXPECT_TRUE(solution_.containsDuplicate(nums));
}

TEST_P(ContainsDuplicateTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{7};
  EXPECT_FALSE(solution_.containsDuplicate(nums));
}

INSTANTIATE_TEST_SUITE_P(
    ContainsDuplicateStrategies, ContainsDuplicateTest,
    ::testing::ValuesIn(ContainsDuplicateSolution().getStrategyNames()));

}  // namespace problem_217
}  // namespace leetcode
