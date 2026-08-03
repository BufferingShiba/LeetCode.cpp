#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/check-if-the-number-is-fascinating.h"

namespace leetcode {
namespace problem_2729 {

class CheckIfTheNumberIsFascinatingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  CheckIfTheNumberIsFascinatingSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CheckIfTheNumberIsFascinatingTest, Example1) {
  EXPECT_TRUE(solution.isFascinating(192));
}

TEST_P(CheckIfTheNumberIsFascinatingTest, Example2) {
  EXPECT_FALSE(solution.isFascinating(100));
}

TEST_P(CheckIfTheNumberIsFascinatingTest, SelfAuthored1) {
  EXPECT_FALSE(solution.isFascinating(123));
}

TEST_P(CheckIfTheNumberIsFascinatingTest, SelfAuthored2) {
  EXPECT_FALSE(solution.isFascinating(200));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfTheNumberIsFascinatingTestSuite,
    CheckIfTheNumberIsFascinatingTest,
    ::testing::ValuesIn(CheckIfTheNumberIsFascinatingSolution().getStrategyNames()));

}  // namespace problem_2729
}  // namespace leetcode
