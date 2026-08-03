#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/convert-to-base-2.h"

namespace leetcode {
namespace problem_1017 {

class ConvertToBase2Test : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConvertToBase2Solution solution_;
};

TEST_P(ConvertToBase2Test, Example1) {
  EXPECT_EQ(solution_.baseNeg2(2), "110");
}

TEST_P(ConvertToBase2Test, Example2) {
  EXPECT_EQ(solution_.baseNeg2(3), "111");
}

TEST_P(ConvertToBase2Test, Example3) {
  EXPECT_EQ(solution_.baseNeg2(4), "100");
}

TEST_P(ConvertToBase2Test, SelfAuthored) {
  EXPECT_EQ(solution_.baseNeg2(0), "0");
  EXPECT_EQ(solution_.baseNeg2(1), "1");
  EXPECT_EQ(solution_.baseNeg2(5), "101");   // (-2)^2 + (-2)^0 = 4 + 1
  EXPECT_EQ(solution_.baseNeg2(9), "11001"); // (-2)^4 + (-2)^3 + (-2)^0 = 16-8+1=9
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ConvertToBase2Test,
    ::testing::ValuesIn(ConvertToBase2Solution().getStrategyNames()));

}  // namespace problem_1017
}  // namespace leetcode
