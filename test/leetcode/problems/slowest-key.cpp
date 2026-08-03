#include <gtest/gtest.h>

#include "leetcode/problems/slowest-key.h"
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1629 {

class SlowestKeyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SlowestKeySolution solution;
};

TEST_P(SlowestKeyTest, Example1) {
  std::vector<int> releaseTimes = {9, 29, 49, 50};
  std::string keysPressed = "cbcd";
  EXPECT_EQ('c', solution.slowestKey(releaseTimes, keysPressed));
}

TEST_P(SlowestKeyTest, Example2) {
  std::vector<int> releaseTimes = {12, 23, 36, 46, 62};
  std::string keysPressed = "spuda";
  EXPECT_EQ('a', solution.slowestKey(releaseTimes, keysPressed));
}

TEST_P(SlowestKeyTest, SelfAuthoredSinglePress) {
  std::vector<int> releaseTimes = {5, 10};
  std::string keysPressed = "ab";
  // duration: a=5, b=5, tie -> lexicographically larger is 'b'
  EXPECT_EQ('b', solution.slowestKey(releaseTimes, keysPressed));
}

INSTANTIATE_TEST_SUITE_P(
    SlowestKeyTestSuite, SlowestKeyTest,
    ::testing::ValuesIn(SlowestKeySolution().getStrategyNames()));

}  // namespace problem_1629
}  // namespace leetcode
