#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/remove-zeros-in-decimal-representation.h"

namespace leetcode {
namespace problem_3726 {

class RemoveZerosInDecimalRepresentationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveZerosInDecimalRepresentationSolution solution;
};

TEST_P(RemoveZerosInDecimalRepresentationTest, Example1) {
  EXPECT_EQ(solution.removeZeros(1020030), 123);
}

TEST_P(RemoveZerosInDecimalRepresentationTest, Example2) {
  EXPECT_EQ(solution.removeZeros(1), 1);
}

TEST_P(RemoveZerosInDecimalRepresentationTest, SelfAuthoredAllZeros) {
  EXPECT_EQ(solution.removeZeros(1000), 1);
}

TEST_P(RemoveZerosInDecimalRepresentationTest, SelfAuthoredNoZeros) {
  EXPECT_EQ(solution.removeZeros(12345), 12345);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveZerosInDecimalRepresentationTestSuite,
    RemoveZerosInDecimalRepresentationTest,
    ::testing::ValuesIn(
        RemoveZerosInDecimalRepresentationSolution().getStrategyNames()));

}  // namespace problem_3726
}  // namespace leetcode
