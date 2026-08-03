#include "leetcode/problems/positions-of-large-groups.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_830 {
namespace {

PositionsOfLargeGroupsSolution solution_instance;

}  // namespace

class PositionsOfLargeGroupsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_instance.setStrategy(GetParam());
  }
};

TEST_P(PositionsOfLargeGroupsTest, Example1) {
  std::string s = "abbxxxxzzy";
  std::vector<std::vector<int>> expected = {{3, 6}};
  EXPECT_EQ(solution_instance.largeGroupPositions(s), expected);
}

TEST_P(PositionsOfLargeGroupsTest, Example2) {
  std::string s = "abc";
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(solution_instance.largeGroupPositions(s), expected);
}

TEST_P(PositionsOfLargeGroupsTest, Example3) {
  std::string s = "abcdddeeeeaabbbcd";
  std::vector<std::vector<int>> expected = {{3, 5}, {6, 9}, {12, 14}};
  EXPECT_EQ(solution_instance.largeGroupPositions(s), expected);
}

TEST_P(PositionsOfLargeGroupsTest, SelfAuthoredSingleChar) {
  std::string s = "a";
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(solution_instance.largeGroupPositions(s), expected);
}

TEST_P(PositionsOfLargeGroupsTest, SelfAuthoredThreeSame) {
  std::string s = "aaa";
  std::vector<std::vector<int>> expected = {{0, 2}};
  EXPECT_EQ(solution_instance.largeGroupPositions(s), expected);
}

INSTANTIATE_TEST_SUITE_P(
    PositionsOfLargeGroupsTestSuite,
    PositionsOfLargeGroupsTest,
    ::testing::ValuesIn(PositionsOfLargeGroupsSolution().getStrategyNames()));

}  // namespace problem_830
}  // namespace leetcode
