#include <gtest/gtest.h>

#include "leetcode/problems/find-the-key-of-the-numbers.h"

namespace leetcode::problem_3270 {
namespace {

class FindTheKeyOfTheNumbersTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheKeyOfTheNumbersSolution solution_;
};

TEST_P(FindTheKeyOfTheNumbersTest, Example1) {
  EXPECT_EQ(solution_.generateKey(1, 10, 1000), 0);
}

TEST_P(FindTheKeyOfTheNumbersTest, Example2) {
  EXPECT_EQ(solution_.generateKey(987, 879, 798), 777);
}

TEST_P(FindTheKeyOfTheNumbersTest, Example3) {
  EXPECT_EQ(solution_.generateKey(1, 2, 3), 1);
}

INSTANTIATE_TEST_SUITE_P(
    , FindTheKeyOfTheNumbersTest,
    testing::ValuesIn(FindTheKeyOfTheNumbersSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3270
