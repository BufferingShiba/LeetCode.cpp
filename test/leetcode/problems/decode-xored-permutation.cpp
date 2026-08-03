#include <gtest/gtest.h>

#include "leetcode/problems/decode-xored-permutation.h"

using namespace leetcode::problem_1734;

class DecodeXoredPermutationTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  DecodeXoredPermutationSolution solution;
};

TEST_P(DecodeXoredPermutationTest, OfficialExample1) {
  std::vector<int> encoded = {3, 1};
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(solution.decode(encoded), expected);
}

TEST_P(DecodeXoredPermutationTest, OfficialExample2) {
  std::vector<int> encoded = {6, 5, 4, 6};
  std::vector<int> expected = {2, 4, 1, 5, 3};
  EXPECT_EQ(solution.decode(encoded), expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, DecodeXoredPermutationTest,
    testing::ValuesIn(DecodeXoredPermutationSolution().getStrategyNames()));
