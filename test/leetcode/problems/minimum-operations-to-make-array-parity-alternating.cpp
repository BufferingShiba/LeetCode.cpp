#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-make-array-parity-alternating.h"

namespace leetcode {
namespace problem_3854 {

class MinimumOperationsToMakeArrayParityAlternatingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumOperationsToMakeArrayParityAlternatingSolution solution_;
};

TEST_P(MinimumOperationsToMakeArrayParityAlternatingTest, Example1) {
  std::vector<int> nums = {-2, -3, 1, 4};
  std::vector<int> expected = {2, 6};
  EXPECT_EQ(solution_.makeParityAlternating(nums), expected);
}

TEST_P(MinimumOperationsToMakeArrayParityAlternatingTest, Example2) {
  std::vector<int> nums = {0, 2, -2};
  std::vector<int> expected = {1, 3};
  EXPECT_EQ(solution_.makeParityAlternating(nums), expected);
}

TEST_P(MinimumOperationsToMakeArrayParityAlternatingTest, Example3) {
  std::vector<int> nums = {7};
  std::vector<int> expected = {0, 0};
  EXPECT_EQ(solution_.makeParityAlternating(nums), expected);
}

TEST_P(MinimumOperationsToMakeArrayParityAlternatingTest, SelfAuthoredAlreadyAlternating) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> expected = {0, 3};
  EXPECT_EQ(solution_.makeParityAlternating(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToMakeArrayParityAlternatingTest,
    MinimumOperationsToMakeArrayParityAlternatingTest,
    ::testing::ValuesIn(
        MinimumOperationsToMakeArrayParityAlternatingSolution()
            .getStrategyNames()));

}  // namespace problem_3854
}  // namespace leetcode
