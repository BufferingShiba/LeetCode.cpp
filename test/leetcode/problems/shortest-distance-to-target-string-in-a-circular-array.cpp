#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/shortest-distance-to-target-string-in-a-circular-array.h"

namespace leetcode::problem_2515 {

class ShortestDistanceToTargetStringInACircularArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  ShortestDistanceToTargetStringInACircularArraySolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ShortestDistanceToTargetStringInACircularArrayTest, Example1) {
  std::vector<std::string> words = {"hello", "i", "am", "leetcode", "hello"};
  std::string target = "hello";
  int startIndex = 1;
  EXPECT_EQ(solution.closestTarget(words, target, startIndex), 1);
}

TEST_P(ShortestDistanceToTargetStringInACircularArrayTest, Example2) {
  std::vector<std::string> words = {"a", "b", "leetcode"};
  std::string target = "leetcode";
  int startIndex = 0;
  EXPECT_EQ(solution.closestTarget(words, target, startIndex), 1);
}

TEST_P(ShortestDistanceToTargetStringInACircularArrayTest, Example3) {
  std::vector<std::string> words = {"i", "eat", "leetcode"};
  std::string target = "ate";
  int startIndex = 0;
  EXPECT_EQ(solution.closestTarget(words, target, startIndex), -1);
}

TEST_P(ShortestDistanceToTargetStringInACircularArrayTest, SelfAuthoredTargetAtStart) {
  std::vector<std::string> words = {"abc", "def", "ghi"};
  std::string target = "abc";
  int startIndex = 0;
  EXPECT_EQ(solution.closestTarget(words, target, startIndex), 0);
}

TEST_P(ShortestDistanceToTargetStringInACircularArrayTest, SelfAuthoredCircularWrap) {
  std::vector<std::string> words = {"a", "b", "c", "d", "e"};
  std::string target = "a";
  int startIndex = 3;
  EXPECT_EQ(solution.closestTarget(words, target, startIndex), 2);
}

INSTANTIATE_TEST_SUITE_P(
    ShortestDistanceToTargetStringInACircularArrayTestSuite,
    ShortestDistanceToTargetStringInACircularArrayTest,
    ::testing::ValuesIn(
        ShortestDistanceToTargetStringInACircularArraySolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_2515
