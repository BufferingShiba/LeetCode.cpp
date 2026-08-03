#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/shortest-distance-to-a-character.h"

namespace leetcode {
namespace problem_821 {

class ShortestDistanceToACharacterTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ShortestDistanceToACharacterSolution solution;
};

TEST_P(ShortestDistanceToACharacterTest, Example1) {
  std::vector<int> expected = {3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
  EXPECT_EQ(expected, solution.shortestToChar("loveleetcode", 'e'));
}

TEST_P(ShortestDistanceToACharacterTest, Example2) {
  std::vector<int> expected = {3, 2, 1, 0};
  EXPECT_EQ(expected, solution.shortestToChar("aaab", 'b'));
}

TEST_P(ShortestDistanceToACharacterTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(std::vector<int>{0}, solution.shortestToChar("a", 'a'));
}

TEST_P(ShortestDistanceToACharacterTest, SelfAuthoredCharAtEnd) {
  std::vector<int> expected = {3, 2, 1, 0};
  EXPECT_EQ(expected, solution.shortestToChar("aaab", 'b'));
}

TEST_P(ShortestDistanceToACharacterTest, SelfAuthoredCharAtStart) {
  std::vector<int> expected = {0, 1, 2, 3};
  EXPECT_EQ(expected, solution.shortestToChar("baaa", 'b'));
}

INSTANTIATE_TEST_SUITE_P(
    ShortestDistanceToACharacterTestSuite, ShortestDistanceToACharacterTest,
    ::testing::ValuesIn(
        ShortestDistanceToACharacterSolution().getStrategyNames()));

}  // namespace problem_821
}  // namespace leetcode
