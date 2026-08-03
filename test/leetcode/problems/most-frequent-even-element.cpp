#include "leetcode/problems/most-frequent-even-element.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2404 {

class MostFrequentEvenElementTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MostFrequentEvenElementSolution solution_;
};

TEST_P(MostFrequentEvenElementTest, Example1) {
  std::vector<int> nums = {0, 1, 2, 2, 4, 4, 1};
  EXPECT_EQ(solution_.mostFrequentEven(nums), 2);
}

TEST_P(MostFrequentEvenElementTest, Example2) {
  std::vector<int> nums = {4, 4, 4, 9, 2, 4};
  EXPECT_EQ(solution_.mostFrequentEven(nums), 4);
}

TEST_P(MostFrequentEvenElementTest, Example3) {
  std::vector<int> nums = {29, 47, 21, 41, 13, 37, 25, 7};
  EXPECT_EQ(solution_.mostFrequentEven(nums), -1);
}

TEST_P(MostFrequentEvenElementTest, SelfAuthoredSingleEven) {
  std::vector<int> nums = {3, 5, 8, 1};
  EXPECT_EQ(solution_.mostFrequentEven(nums), 8);
}

TEST_P(MostFrequentEvenElementTest, SelfAuthoredTieSmallest) {
  std::vector<int> nums = {2, 6, 2, 6, 4};
  EXPECT_EQ(solution_.mostFrequentEven(nums), 2);
}

TEST_P(MostFrequentEvenElementTest, SelfAuthoredZero) {
  std::vector<int> nums = {0, 0, 0, 1};
  EXPECT_EQ(solution_.mostFrequentEven(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MostFrequentEvenElementTestSuite, MostFrequentEvenElementTest,
    ::testing::ValuesIn(MostFrequentEvenElementSolution().getStrategyNames()));

}  // namespace problem_2404
}  // namespace leetcode
