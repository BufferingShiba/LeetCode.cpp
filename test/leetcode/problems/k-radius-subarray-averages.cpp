#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/k-radius-subarray-averages.h"

namespace leetcode {
namespace problem_2090 {

class KRadiusSubarrayAveragesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  KRadiusSubarrayAveragesSolution solution_;
};

TEST_P(KRadiusSubarrayAveragesTest, Example1) {
  std::vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
  int k = 3;
  std::vector<int> expected = {-1, -1, -1, 5, 4, 4, -1, -1, -1};
  EXPECT_EQ(solution_.getSolution()(nums, k), expected);
}

TEST_P(KRadiusSubarrayAveragesTest, Example2) {
  std::vector<int> nums = {100000};
  int k = 0;
  std::vector<int> expected = {100000};
  EXPECT_EQ(solution_.getSolution()(nums, k), expected);
}

TEST_P(KRadiusSubarrayAveragesTest, Example3) {
  std::vector<int> nums = {8};
  int k = 100000;
  std::vector<int> expected = {-1};
  EXPECT_EQ(solution_.getSolution()(nums, k), expected);
}

TEST_P(KRadiusSubarrayAveragesTest, SelfAuthoredZeroRadiusAllValid) {
  std::vector<int> nums = {1, 2, 3, 4};
  int k = 0;
  std::vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(solution_.getSolution()(nums, k), expected);
}

TEST_P(KRadiusSubarrayAveragesTest, SelfAuthoredRadiusOneEdges) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int k = 1;
  std::vector<int> expected = {-1, 2, 3, 4, -1};
  EXPECT_EQ(solution_.getSolution()(nums, k), expected);
}

INSTANTIATE_TEST_SUITE_P(
    KRadiusSubarrayAveragesTestSuite, KRadiusSubarrayAveragesTest,
    ::testing::ValuesIn(KRadiusSubarrayAveragesSolution().getStrategyNames()));

}  // namespace problem_2090
}  // namespace leetcode
