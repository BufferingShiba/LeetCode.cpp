#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-flowers-in-full-bloom.h"

namespace leetcode {
namespace problem_2251 {

class NumberOfFlowersInFullBloomTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfFlowersInFullBloomSolution solution;
};

TEST_P(NumberOfFlowersInFullBloomTest, Example1) {
  std::vector<std::vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
  std::vector<int> people = {2, 3, 7, 11};
  std::vector<int> expected = {1, 2, 2, 2};
  EXPECT_EQ(solution.fullBloomFlowers(flowers, people), expected);
}

TEST_P(NumberOfFlowersInFullBloomTest, Example2) {
  std::vector<std::vector<int>> flowers = {{1, 10}, {3, 3}};
  std::vector<int> people = {3, 3, 2};
  std::vector<int> expected = {2, 2, 1};
  EXPECT_EQ(solution.fullBloomFlowers(flowers, people), expected);
}

TEST_P(NumberOfFlowersInFullBloomTest, SelfAuthoredSingleFlowerInclusiveBoundary) {
  std::vector<std::vector<int>> flowers = {{5, 5}};
  std::vector<int> people = {4, 5, 6};
  std::vector<int> expected = {0, 1, 0};
  EXPECT_EQ(solution.fullBloomFlowers(flowers, people), expected);
}

TEST_P(NumberOfFlowersInFullBloomTest, SelfAuthoredNoFlowerAtTime) {
  std::vector<std::vector<int>> flowers = {{1, 2}, {10, 12}};
  std::vector<int> people = {5, 3};
  std::vector<int> expected = {0, 0};
  EXPECT_EQ(solution.fullBloomFlowers(flowers, people), expected);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfFlowersInFullBloomTestSuite, NumberOfFlowersInFullBloomTest,
    ::testing::ValuesIn(NumberOfFlowersInFullBloomSolution().getStrategyNames()));

}  // namespace problem_2251
}  // namespace leetcode
