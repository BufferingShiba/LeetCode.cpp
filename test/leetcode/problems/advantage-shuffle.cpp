#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/advantage-shuffle.h"

namespace leetcode::problem_870 {

class AdvantageShuffleTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  AdvantageShuffleSolution solution;
};

// Verify the result is a valid permutation of nums1 with maximum advantage.
static int ComputeAdvantage(const std::vector<int>& res, const std::vector<int>& nums2) {
  int adv = 0;
  for (size_t i = 0; i < res.size(); ++i) {
    if (res[i] > nums2[i]) {
      ++adv;
    }
  }
  return adv;
}

TEST_P(AdvantageShuffleTest, Example1) {
  std::vector<int> nums1{2, 7, 11, 15};
  std::vector<int> nums2{1, 10, 4, 11};
  auto result = solution.advantageCount(nums1, nums2);
  EXPECT_EQ(ComputeAdvantage(result, nums2), 4);
  auto sorted = result;
  std::sort(sorted.begin(), sorted.end());
  std::vector<int> sorted1{2, 7, 11, 15};
  EXPECT_EQ(sorted, sorted1);
}

TEST_P(AdvantageShuffleTest, Example2) {
  std::vector<int> nums1{12, 24, 8, 32};
  std::vector<int> nums2{13, 25, 32, 11};
  auto result = solution.advantageCount(nums1, nums2);
  EXPECT_EQ(ComputeAdvantage(result, nums2), 3);
  auto sorted = result;
  std::sort(sorted.begin(), sorted.end());
  std::vector<int> sorted1{12, 24, 8, 32};
  std::sort(sorted1.begin(), sorted1.end());
  EXPECT_EQ(sorted, sorted1);
}

TEST_P(AdvantageShuffleTest, SelfAuthoredSingleElement) {
  std::vector<int> nums1{5};
  std::vector<int> nums2{3};
  auto result = solution.advantageCount(nums1, nums2);
  EXPECT_EQ(ComputeAdvantage(result, nums2), 1);
}

TEST_P(AdvantageShuffleTest, SelfAuthoredCannotWinAny) {
  std::vector<int> nums1{1, 2, 3};
  std::vector<int> nums2{4, 4, 4};
  auto result = solution.advantageCount(nums1, nums2);
  EXPECT_EQ(ComputeAdvantage(result, nums2), 0);
}

TEST_P(AdvantageShuffleTest, SelfAuthoredAllEqual) {
  std::vector<int> nums1{5, 5, 5};
  std::vector<int> nums2{5, 5, 5};
  auto result = solution.advantageCount(nums1, nums2);
  EXPECT_EQ(ComputeAdvantage(result, nums2), 0);
}

INSTANTIATE_TEST_SUITE_P(
    AdvantageShuffleTestSuite,
    AdvantageShuffleTest,
    ::testing::ValuesIn(AdvantageShuffleSolution().getStrategyNames()));

}  // namespace leetcode::problem_870
