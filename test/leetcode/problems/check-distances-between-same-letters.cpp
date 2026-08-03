#include <gtest/gtest.h>
#include "leetcode/problems/check-distances-between-same-letters.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2399 {
namespace {

class CheckDistancesBetweenSameLettersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckDistancesBetweenSameLettersSolution solution_;
};

TEST_P(CheckDistancesBetweenSameLettersTest, Example1) {
  std::string s = "abaccb";
  std::vector<int> distance = {1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_TRUE(solution_.checkDistances(s, distance));
}

TEST_P(CheckDistancesBetweenSameLettersTest, Example2) {
  std::string s = "aa";
  std::vector<int> distance(26, 0);
  distance[0] = 1;
  EXPECT_FALSE(solution_.checkDistances(s, distance));
}

TEST_P(CheckDistancesBetweenSameLettersTest, SelfAuthoredWellSpacedTwoLetters) {
  std::string s = "abba";
  std::vector<int> distance(26, 0);
  distance[0] = 2;  // 'a' at 0 and 3, gap = 2
  distance[1] = 0;  // 'b' at 1 and 2, gap = 0
  EXPECT_TRUE(solution_.checkDistances(s, distance));
}

INSTANTIATE_TEST_SUITE_P(
    CheckDistancesBetweenSameLettersTestSuite,
    CheckDistancesBetweenSameLettersTest,
    ::testing::ValuesIn(
        CheckDistancesBetweenSameLettersSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2399
}  // namespace leetcode
