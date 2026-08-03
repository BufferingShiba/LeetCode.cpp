#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-of-integers.h"

namespace leetcode::problem_2719 {

class CountOfIntegersTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountOfIntegersSolution solution_;
};

TEST_P(CountOfIntegersTest, Example1) {
  EXPECT_EQ(solution_.count("1", "12", 1, 8), 11);
}

TEST_P(CountOfIntegersTest, Example2) {
  EXPECT_EQ(solution_.count("1", "5", 1, 5), 5);
}

INSTANTIATE_TEST_SUITE_P(
    CountOfIntegersTests, CountOfIntegersTest,
    ::testing::ValuesIn(CountOfIntegersSolution().getStrategyNames()));

}  // namespace leetcode::problem_2719
