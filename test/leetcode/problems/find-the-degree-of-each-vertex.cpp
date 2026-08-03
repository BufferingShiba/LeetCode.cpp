#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-degree-of-each-vertex.h"

namespace leetcode {
namespace problem_3898 {

class FindTheDegreeOfEachVertexTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheDegreeOfEachVertexSolution solution_;
};

TEST_P(FindTheDegreeOfEachVertexTest, Example1) {
  std::vector<std::vector<int>> matrix = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
  std::vector<int> expected = {2, 2, 2};
  EXPECT_EQ(solution_.findDegrees(matrix), expected);
}

TEST_P(FindTheDegreeOfEachVertexTest, Example2) {
  std::vector<std::vector<int>> matrix = {{0, 1, 0}, {1, 0, 0}, {0, 0, 0}};
  std::vector<int> expected = {1, 1, 0};
  EXPECT_EQ(solution_.findDegrees(matrix), expected);
}

TEST_P(FindTheDegreeOfEachVertexTest, Example3) {
  std::vector<std::vector<int>> matrix = {{0}};
  std::vector<int> expected = {0};
  EXPECT_EQ(solution_.findDegrees(matrix), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheDegreeOfEachVertexTestSuite, FindTheDegreeOfEachVertexTest,
    ::testing::ValuesIn(FindTheDegreeOfEachVertexSolution().getStrategyNames()));

}  // namespace problem_3898
}  // namespace leetcode
