#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/largest-even-number.h"

namespace leetcode {
namespace problem_3798 {
namespace test {

class LargestEvenNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestEvenNumberSolution solution;
};

TEST_P(LargestEvenNumberTest, Example1) {
  EXPECT_EQ(solution.largestEven("1112"), "1112");
}

TEST_P(LargestEvenNumberTest, Example2) {
  EXPECT_EQ(solution.largestEven("221"), "22");
}

TEST_P(LargestEvenNumberTest, Example3) {
  EXPECT_EQ(solution.largestEven("1"), "");
}

TEST_P(LargestEvenNumberTest, SelfAuthoredAllTwos) {
  EXPECT_EQ(solution.largestEven("222"), "222");
}

TEST_P(LargestEvenNumberTest, SelfAuthoredSingleTwo) {
  EXPECT_EQ(solution.largestEven("2"), "2");
}

INSTANTIATE_TEST_SUITE_P(
    LargestEvenNumberTestCases, LargestEvenNumberTest,
    ::testing::ValuesIn(LargestEvenNumberSolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_3798
}  // namespace leetcode
