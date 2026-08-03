#include "leetcode/problems/ones-and-zeroes.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_474 {

class OnesAndZeroesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  OnesAndZeroesSolution solution_;
};

TEST_P(OnesAndZeroesTest, Example1) {
  std::vector<std::string> strs = {"10", "0001", "111001", "1", "0"};
  EXPECT_EQ(4, solution_.findMaxForm(strs, 5, 3));
}

TEST_P(OnesAndZeroesTest, Example2) {
  std::vector<std::string> strs = {"10", "0", "1"};
  EXPECT_EQ(2, solution_.findMaxForm(strs, 1, 1));
}

TEST_P(OnesAndZeroesTest, SelfAuthoredAllStrsWithinLimits) {
  std::vector<std::string> strs = {"0", "0", "0", "1", "1", "1"};
  EXPECT_EQ(6, solution_.findMaxForm(strs, 3, 3));
}

TEST_P(OnesAndZeroesTest, SelfAuthoredSingleStringFits) {
  std::vector<std::string> strs = {"01"};
  EXPECT_EQ(1, solution_.findMaxForm(strs, 1, 1));
}

TEST_P(OnesAndZeroesTest, SelfAuthoredSingleStringTooBig) {
  std::vector<std::string> strs = {"0001"};
  EXPECT_EQ(0, solution_.findMaxForm(strs, 1, 1));
}

INSTANTIATE_TEST_SUITE_P(
    OnesAndZeroesTestSuite, OnesAndZeroesTest,
    ::testing::ValuesIn(OnesAndZeroesSolution().getStrategyNames()));

}  // namespace leetcode::problem_474
