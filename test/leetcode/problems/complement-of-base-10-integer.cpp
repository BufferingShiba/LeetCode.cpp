#include <gtest/gtest.h>
#include "leetcode/problems/complement-of-base-10-integer.h"

namespace leetcode {
namespace problem_1009 {

class ComplementOfBase10IntegerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ComplementOfBase10IntegerSolution solution_;
};

TEST_P(ComplementOfBase10IntegerTest, Example1) {
  EXPECT_EQ(solution_.bitwiseComplement(5), 2);
}

TEST_P(ComplementOfBase10IntegerTest, Example2) {
  EXPECT_EQ(solution_.bitwiseComplement(7), 0);
}

TEST_P(ComplementOfBase10IntegerTest, Example3) {
  EXPECT_EQ(solution_.bitwiseComplement(10), 5);
}

TEST_P(ComplementOfBase10IntegerTest, Zero) {
  EXPECT_EQ(solution_.bitwiseComplement(0), 1);
}

TEST_P(ComplementOfBase10IntegerTest, PowerOfTwo) {
  EXPECT_EQ(solution_.bitwiseComplement(1), 0);
}

TEST_P(ComplementOfBase10IntegerTest, AllOnes) {
  // 1048575 = 2^20 - 1, binary all ones -> complement 0
  EXPECT_EQ(solution_.bitwiseComplement(1048575), 0);
}

INSTANTIATE_TEST_SUITE_P(
    ComplementOfBase10IntegerParam, ComplementOfBase10IntegerTest,
    ::testing::ValuesIn(ComplementOfBase10IntegerSolution().getStrategyNames()));

}  // namespace problem_1009
}  // namespace leetcode
