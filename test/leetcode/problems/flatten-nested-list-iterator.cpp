#include <gtest/gtest.h>

#include "leetcode/problems/flatten-nested-list-iterator.h"

namespace leetcode::problem_341 {

class FlattenNestedListIteratorTest : public ::testing::TestWithParam<int> {
 protected:
  FlattenNestedListIteratorSolution solution;
};

TEST_P(FlattenNestedListIteratorTest, Example1) {
  // nestedList = [[1,1],2,[1,1]]
  std::vector<NestedInteger> nestedList = {
      NestedInteger(std::vector<NestedInteger>{NestedInteger(1), NestedInteger(1)}),
      NestedInteger(2),
      NestedInteger(std::vector<NestedInteger>{NestedInteger(1), NestedInteger(1)})};

  auto result = solution.flatten(nestedList);
  std::vector<int> expected = {1, 1, 2, 1, 1};
  EXPECT_EQ(result, expected);
}

TEST_P(FlattenNestedListIteratorTest, Example2) {
  // nestedList = [1,[4,[6]]]
  std::vector<NestedInteger> nestedList = {
      NestedInteger(1),
      NestedInteger(std::vector<NestedInteger>{
          NestedInteger(4),
          NestedInteger(std::vector<NestedInteger>{NestedInteger(6)})})};

  auto result = solution.flatten(nestedList);
  std::vector<int> expected = {1, 4, 6};
  EXPECT_EQ(result, expected);
}

TEST_P(FlattenNestedListIteratorTest, SelfAuthoredEmptyList) {
  std::vector<NestedInteger> nestedList;
  auto result = solution.flatten(nestedList);
  EXPECT_TRUE(result.empty());
}

TEST_P(FlattenNestedListIteratorTest, SelfAuthoredSingleInteger) {
  std::vector<NestedInteger> nestedList = {NestedInteger(42)};
  auto result = solution.flatten(nestedList);
  std::vector<int> expected = {42};
  EXPECT_EQ(result, expected);
}

TEST_P(FlattenNestedListIteratorTest, SelfAuthoredDeeplyNestedEmpty) {
  // [[[[]]]]
  std::vector<NestedInteger> nestedList = {
      NestedInteger(std::vector<NestedInteger>{
          NestedInteger(std::vector<NestedInteger>{
              NestedInteger(std::vector<NestedInteger>{})})})};
  auto result = solution.flatten(nestedList);
  EXPECT_TRUE(result.empty());
}

INSTANTIATE_TEST_SUITE_P(Strategies, FlattenNestedListIteratorTest,
                         ::testing::Values(0));

}  // namespace leetcode::problem_341
