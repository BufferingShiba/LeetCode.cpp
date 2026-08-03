#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-number-of-distinct-colors-among-the-balls.h"

namespace leetcode {
namespace problem_3160 {
namespace {

struct TestCase {
  int limit;
  std::vector<std::vector<int>> queries;
  std::vector<int> expected;
};

}  // namespace

class FindTheNumberOfDistinctColorsAmongTheBallsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindTheNumberOfDistinctColorsAmongTheBallsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindTheNumberOfDistinctColorsAmongTheBallsTest, Example1) {
  std::vector<std::vector<int>> queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
  std::vector<int> expected = {1, 2, 2, 3};
  EXPECT_EQ(solution.queryResults(4, queries), expected);
}

TEST_P(FindTheNumberOfDistinctColorsAmongTheBallsTest, Example2) {
  std::vector<std::vector<int>> queries = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
  std::vector<int> expected = {1, 2, 2, 3, 4};
  EXPECT_EQ(solution.queryResults(4, queries), expected);
}

TEST_P(FindTheNumberOfDistinctColorsAmongTheBallsTest, SelfAuthoredRecolorSingleBall) {
  // Recolor the same ball repeatedly; distinct colors should stay at 1.
  std::vector<std::vector<int>> queries = {{0, 1}, {0, 2}, {0, 3}};
  std::vector<int> expected = {1, 1, 1};
  EXPECT_EQ(solution.queryResults(0, queries), expected);
}

TEST_P(FindTheNumberOfDistinctColorsAmongTheBallsTest, SelfAuthoredSameColorMultipleBalls) {
  // Multiple balls share the same color; still counts as one distinct color.
  std::vector<std::vector<int>> queries = {{0, 5}, {1, 5}, {2, 5}};
  std::vector<int> expected = {1, 1, 1};
  EXPECT_EQ(solution.queryResults(2, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheNumberOfDistinctColorsAmongTheBallsTestInstance,
    FindTheNumberOfDistinctColorsAmongTheBallsTest,
    ::testing::ValuesIn(FindTheNumberOfDistinctColorsAmongTheBallsSolution().getStrategyNames()));

}  // namespace problem_3160
}  // namespace leetcode
