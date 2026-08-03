#include <gtest/gtest.h>
#include "leetcode/problems/sum-of-k-mirror-numbers.h"

namespace leetcode {
namespace problem_2081 {
namespace {

class SumOfKMirrorNumbersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SumOfKMirrorNumbersSolution solution_;
};

TEST_P(SumOfKMirrorNumbersTest, Example1) {
  EXPECT_EQ(solution_.kMirror(2, 5), 25);
}

TEST_P(SumOfKMirrorNumbersTest, Example2) {
  EXPECT_EQ(solution_.kMirror(3, 7), 499);
}

TEST_P(SumOfKMirrorNumbersTest, Example3) {
  EXPECT_EQ(solution_.kMirror(7, 17), 20379000);
}

TEST_P(SumOfKMirrorNumbersTest, SelfAuthoredSingleMinimal) {
  // The smallest k-mirror number is always 1.
  for (int k = 2; k <= 9; ++k) {
    EXPECT_EQ(solution_.kMirror(k, 1), 1);
  }
}

TEST_P(SumOfKMirrorNumbersTest, SelfAuthoredBinaryFirstThree) {
  // base-2: 1, 3, 5 -> 9
  EXPECT_EQ(solution_.kMirror(2, 3), 9);
}

INSTANTIATE_TEST_SUITE_P(
    SumOfKMirrorNumbersTestParameters, SumOfKMirrorNumbersTest,
    ::testing::ValuesIn(SumOfKMirrorNumbersSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2081
}  // namespace leetcode
