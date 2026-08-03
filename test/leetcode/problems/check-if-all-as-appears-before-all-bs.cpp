#include <gtest/gtest.h>

#include "leetcode/problems/check-if-all-as-appears-before-all-bs.h"

namespace leetcode {
namespace problem_2124 {

class CheckIfAllAsAppearsBeforeAllBsTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CheckIfAllAsAppearsBeforeAllBsSolution solution;
};

TEST_P(CheckIfAllAsAppearsBeforeAllBsTest, Example1) {
  EXPECT_TRUE(solution.checkString("aaabbb"));
}

TEST_P(CheckIfAllAsAppearsBeforeAllBsTest, Example2) {
  EXPECT_FALSE(solution.checkString("abab"));
}

TEST_P(CheckIfAllAsAppearsBeforeAllBsTest, Example3) {
  EXPECT_TRUE(solution.checkString("bbb"));
}

TEST_P(CheckIfAllAsAppearsBeforeAllBsTest, SelfAuthoredSingleA) {
  EXPECT_TRUE(solution.checkString("a"));
}

TEST_P(CheckIfAllAsAppearsBeforeAllBsTest, SelfAuthoredMixed) {
  EXPECT_FALSE(solution.checkString("ba"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfAllAsAppearsBeforeAllBsTestInstance,
    CheckIfAllAsAppearsBeforeAllBsTest,
    ::testing::ValuesIn(
        CheckIfAllAsAppearsBeforeAllBsSolution().getStrategyNames()));

}  // namespace problem_2124
}  // namespace leetcode
