#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-operations-to-obtain-zero.h"

namespace leetcode {
namespace problem_2169 {
namespace {

class CountOperationsToObtainZeroTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountOperationsToObtainZeroSolution solution_;
};

TEST_P(CountOperationsToObtainZeroTest, Example1) {
  EXPECT_EQ(solution_.countOperations(2, 3), 3);
}

TEST_P(CountOperationsToObtainZeroTest, Example2) {
  EXPECT_EQ(solution_.countOperations(10, 10), 1);
}

TEST_P(CountOperationsToObtainZeroTest, ZeroInput) {
  EXPECT_EQ(solution_.countOperations(0, 5), 0);
  EXPECT_EQ(solution_.countOperations(7, 0), 0);
}

TEST_P(CountOperationsToObtainZeroTest, SimpleSubtraction) {
  EXPECT_EQ(solution_.countOperations(10, 3), 6);
}

INSTANTIATE_TEST_SUITE_P(
    CountOperationsToObtainZeroTestSuite, CountOperationsToObtainZeroTest,
    ::testing::ValuesIn(CountOperationsToObtainZeroSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2169
}  // namespace leetcode
