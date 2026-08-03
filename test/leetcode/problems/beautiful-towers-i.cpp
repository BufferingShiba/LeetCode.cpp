#include "leetcode/problems/beautiful-towers-i.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2865 {

class BeautifulTowersITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BeautifulTowersISolution solution;
};

TEST_P(BeautifulTowersITest, Example1) {
  std::vector<int> heights = {5, 3, 4, 1, 1};
  EXPECT_EQ(13LL, solution.maximumSumOfHeights(heights));
}

TEST_P(BeautifulTowersITest, Example2) {
  std::vector<int> heights = {6, 5, 3, 9, 2, 7};
  EXPECT_EQ(22LL, solution.maximumSumOfHeights(heights));
}

TEST_P(BeautifulTowersITest, Example3) {
  std::vector<int> heights = {3, 2, 5, 5, 2, 3};
  EXPECT_EQ(18LL, solution.maximumSumOfHeights(heights));
}

TEST_P(BeautifulTowersITest, SelfAuthoredSingleElement) {
  std::vector<int> heights = {7};
  EXPECT_EQ(7LL, solution.maximumSumOfHeights(heights));
}

TEST_P(BeautifulTowersITest, SelfAuthoredStrictlyDecreasing) {
  std::vector<int> heights = {4, 3, 2, 1};
  // Peak at index 0: [4,3,2,1] sum = 10.
  EXPECT_EQ(10LL, solution.maximumSumOfHeights(heights));
}

TEST_P(BeautifulTowersITest, SelfAuthoredStrictlyIncreasing) {
  std::vector<int> heights = {1, 2, 3, 4};
  // Peak at index 3: [1,2,3,4] sum = 10.
  EXPECT_EQ(10LL, solution.maximumSumOfHeights(heights));
}

INSTANTIATE_TEST_SUITE_P(
    BeautifulTowersITests,
    BeautifulTowersITest,
    ::testing::ValuesIn(BeautifulTowersISolution().getStrategyNames()));

}  // namespace problem_2865
}  // namespace leetcode
