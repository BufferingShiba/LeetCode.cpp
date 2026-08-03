#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-beautiful-indices-in-the-given-array-ii.h"

namespace leetcode {
namespace problem_3008 {

class FindBeautifulIndicesInTheGivenArrayIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindBeautifulIndicesInTheGivenArrayIiSolution solution_;
};

TEST_P(FindBeautifulIndicesInTheGivenArrayIiTest, Example1) {
  std::vector<int> expected = {16, 33};
  auto result = solution_.beautifulIndices(
      "isawsquirrelnearmysquirrelhouseohmy", "my", "squirrel", 15);
  EXPECT_EQ(expected, result);
}

TEST_P(FindBeautifulIndicesInTheGivenArrayIiTest, Example2) {
  std::vector<int> expected = {0};
  auto result = solution_.beautifulIndices("abcd", "a", "a", 4);
  EXPECT_EQ(expected, result);
}

TEST_P(FindBeautifulIndicesInTheGivenArrayIiTest, SelfAuthoredNoMatchA) {
  std::vector<int> expected = {};
  auto result = solution_.beautifulIndices("abcdef", "xyz", "a", 2);
  EXPECT_EQ(expected, result);
}

TEST_P(FindBeautifulIndicesInTheGivenArrayIiTest, SelfAuthoredNoMatchB) {
  std::vector<int> expected = {};
  auto result = solution_.beautifulIndices("abcdef", "a", "xyz", 2);
  EXPECT_EQ(expected, result);
}

TEST_P(FindBeautifulIndicesInTheGivenArrayIiTest, SelfAuthoredOverlappingMatch) {
  // a="aa" matches at 0,1 in "aaa"; b="a" matches at 0,1,2.
  std::vector<int> expected = {0, 1};
  auto result = solution_.beautifulIndices("aaa", "aa", "a", 0);
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    FindBeautifulIndicesInTheGivenArrayIiTestSuite,
    FindBeautifulIndicesInTheGivenArrayIiTest,
    ::testing::ValuesIn(
        FindBeautifulIndicesInTheGivenArrayIiSolution().getStrategyNames()));

}  // namespace problem_3008
}  // namespace leetcode
