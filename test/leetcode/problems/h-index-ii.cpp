#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/h-index-ii.h"

namespace leetcode {
namespace problem_275 {

class HIndexIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  HIndexIiSolution solution;
};

TEST_P(HIndexIiTest, Example1) {
  std::vector<int> citations = {0, 1, 3, 5, 6};
  EXPECT_EQ(3, solution.hIndex(citations));
}

TEST_P(HIndexIiTest, Example2) {
  std::vector<int> citations = {1, 2, 100};
  EXPECT_EQ(2, solution.hIndex(citations));
}

TEST_P(HIndexIiTest, SelfAuthoredSinglePaperZeroCitation) {
  std::vector<int> citations = {0};
  EXPECT_EQ(0, solution.hIndex(citations));
}

TEST_P(HIndexIiTest, SelfAuthoredSinglePaperOneCitation) {
  std::vector<int> citations = {1};
  EXPECT_EQ(1, solution.hIndex(citations));
}

TEST_P(HIndexIiTest, SelfAuthoredAllZero) {
  std::vector<int> citations = {0, 0, 0, 0};
  EXPECT_EQ(0, solution.hIndex(citations));
}

TEST_P(HIndexIiTest, SelfAuthoredAllLarge) {
  std::vector<int> citations = {100, 200, 300, 400};
  // n=4, all >=4, so h=4
  EXPECT_EQ(4, solution.hIndex(citations));
}

TEST_P(HIndexIiTest, SelfAuthoredClassicCase) {
  std::vector<int> citations = {0, 1, 2, 5, 6};
  // n=5, h=2 (2 papers with >=2 citations)
  EXPECT_EQ(2, solution.hIndex(citations));
}

INSTANTIATE_TEST_SUITE_P(Strategies, HIndexIiTest,
                         ::testing::ValuesIn(HIndexIiSolution().getStrategyNames()));

}  // namespace problem_275
}  // namespace leetcode
