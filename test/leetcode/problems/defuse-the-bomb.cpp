#include <gtest/gtest.h>
#include "leetcode/problems/defuse-the-bomb.h"
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1652 {
namespace {

class DefuseTheBombTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DefuseTheBombSolution solution;
};

}  // namespace

TEST_P(DefuseTheBombTest, Example1) {
  std::vector<int> code = {5, 7, 1, 4};
  std::vector<int> k = {3};
  // k is passed as arg; call via method
  std::vector<int> expected = {12, 10, 16, 13};
  std::vector<int> input = code;
  EXPECT_EQ(solution.decrypt(input, 3), expected);
}

TEST_P(DefuseTheBombTest, Example2) {
  std::vector<int> input = {1, 2, 3, 4};
  std::vector<int> expected = {0, 0, 0, 0};
  EXPECT_EQ(solution.decrypt(input, 0), expected);
}

TEST_P(DefuseTheBombTest, Example3) {
  std::vector<int> input = {2, 4, 9, 3};
  std::vector<int> expected = {12, 5, 6, 13};
  EXPECT_EQ(solution.decrypt(input, -2), expected);
}

INSTANTIATE_TEST_SUITE_P(DefuseTheBombTestCases, DefuseTheBombTest,
                         ::testing::ValuesIn(DefuseTheBombSolution().getStrategyNames()));

}  // namespace problem_1652
}  // namespace leetcode
