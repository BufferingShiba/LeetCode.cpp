#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/base-7.h"

namespace leetcode {
namespace problem_504 {

class Base7Test : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  Base7Solution solution;
};

TEST_P(Base7Test, Example1) {
  EXPECT_EQ("202", solution.convertToBase7(100));
}

TEST_P(Base7Test, Example2) {
  EXPECT_EQ("-10", solution.convertToBase7(-7));
}

TEST_P(Base7Test, Zero) {
  EXPECT_EQ("0", solution.convertToBase7(0));
}

TEST_P(Base7Test, MinValue) {
  EXPECT_EQ("-150666343", solution.convertToBase7(-10000000));
}

INSTANTIATE_TEST_SUITE_P(Base7TestCases, Base7Test,
                         ::testing::ValuesIn(Base7Solution().getStrategyNames()));

}  // namespace problem_504
}  // namespace leetcode
