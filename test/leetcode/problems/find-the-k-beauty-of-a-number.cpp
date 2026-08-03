#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-k-beauty-of-a-number.h"

namespace leetcode {
namespace problem_2269 {
namespace {

class FindTheKBeautyOfANumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheKBeautyOfANumberSolution solution_;
};

TEST_P(FindTheKBeautyOfANumberTest, Example1) {
  EXPECT_EQ(solution_.divisorSubstrings(240, 2), 2);
}

TEST_P(FindTheKBeautyOfANumberTest, Example2) {
  EXPECT_EQ(solution_.divisorSubstrings(430043, 2), 2);
}

TEST_P(FindTheKBeautyOfANumberTest, SelfAuthoredSingleDigitK1) {
  EXPECT_EQ(solution_.divisorSubstrings(7, 1), 1);
}

TEST_P(FindTheKBeautyOfANumberTest, SelfAuthoredLeadingZeroDivisor) {
  // 10 read as "10", windows of length 1: "1", "0". "0" not a divisor.
  EXPECT_EQ(solution_.divisorSubstrings(10, 1), 1);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheKBeautyOfANumberTestSuite, FindTheKBeautyOfANumberTest,
    ::testing::ValuesIn(FindTheKBeautyOfANumberSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2269
}  // namespace leetcode
