#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-operations-to-make-x-and-y-equal.h"

namespace leetcode {
namespace problem_2998 {

class MinimumNumberOfOperationsToMakeXAndYEqualTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumNumberOfOperationsToMakeXAndYEqualSolution solution_;
};

TEST_P(MinimumNumberOfOperationsToMakeXAndYEqualTest, Example1) {
  EXPECT_EQ(3, solution_.minimumOperationsToMakeEqual(26, 1));
}

TEST_P(MinimumNumberOfOperationsToMakeXAndYEqualTest, Example2) {
  EXPECT_EQ(4, solution_.minimumOperationsToMakeEqual(54, 2));
}

TEST_P(MinimumNumberOfOperationsToMakeXAndYEqualTest, Example3) {
  EXPECT_EQ(5, solution_.minimumOperationsToMakeEqual(25, 30));
}

TEST_P(MinimumNumberOfOperationsToMakeXAndYEqualTest, SelfAuthored) {
  // Already equal
  EXPECT_EQ(0, solution_.minimumOperationsToMakeEqual(7, 7));
  // x <= y only needs increments
  EXPECT_EQ(10, solution_.minimumOperationsToMakeEqual(1, 11));
  // Direct division by 11
  EXPECT_EQ(1, solution_.minimumOperationsToMakeEqual(11, 1));
  // Direct division by 5
  EXPECT_EQ(1, solution_.minimumOperationsToMakeEqual(5, 1));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfOperationsToMakeXAndYEqualTests,
    MinimumNumberOfOperationsToMakeXAndYEqualTest,
    ::testing::ValuesIn(
        MinimumNumberOfOperationsToMakeXAndYEqualSolution()
            .getStrategyNames()));

}  // namespace problem_2998
}  // namespace leetcode
