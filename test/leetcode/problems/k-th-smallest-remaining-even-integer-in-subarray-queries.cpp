#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/k-th-smallest-remaining-even-integer-in-subarray-queries.h"

namespace leetcode {
namespace problem_3911 {
namespace {

class KThSmallestRemainingEvenIntegerInSubarrayQueriesTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  KThSmallestRemainingEvenIntegerInSubarrayQueriesSolution solution_;
};

TEST_P(KThSmallestRemainingEvenIntegerInSubarrayQueriesTest, Example1) {
  std::vector<int> nums = {1, 4, 7};
  std::vector<std::vector<int>> queries = {{0, 2, 1}, {1, 1, 2}, {0, 0, 3}};
  std::vector<int> expected = {2, 6, 6};
  EXPECT_EQ(solution_.kthRemainingInteger(nums, queries), expected);
}

TEST_P(KThSmallestRemainingEvenIntegerInSubarrayQueriesTest, Example2) {
  std::vector<int> nums = {2, 5, 8};
  std::vector<std::vector<int>> queries = {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}};
  std::vector<int> expected = {6, 2, 12};
  EXPECT_EQ(solution_.kthRemainingInteger(nums, queries), expected);
}

TEST_P(KThSmallestRemainingEvenIntegerInSubarrayQueriesTest, Example3) {
  std::vector<int> nums = {3, 6};
  std::vector<std::vector<int>> queries = {{0, 1, 1}, {1, 1, 3}};
  std::vector<int> expected = {2, 8};
  EXPECT_EQ(solution_.kthRemainingInteger(nums, queries), expected);
}

TEST_P(KThSmallestRemainingEvenIntegerInSubarrayQueriesTest,
      SelfAuthoredSingleElementNoEven) {
  // nums = [1], subarray [1], removed none. evens: 2,4,6,...
  std::vector<int> nums = {1};
  std::vector<std::vector<int>> queries = {{0, 0, 1}};
  std::vector<int> expected = {2};
  EXPECT_EQ(solution_.kthRemainingInteger(nums, queries), expected);
}

TEST_P(KThSmallestRemainingEvenIntegerInSubarrayQueriesTest,
      SelfAuthoredSubarrayRemovesOnlyEven) {
  // nums = [2], subarray [2], removed {2}. evens: 4,6,8,...
  std::vector<int> nums = {2};
  std::vector<std::vector<int>> queries = {{0, 0, 1}};
  std::vector<int> expected = {4};
  EXPECT_EQ(solution_.kthRemainingInteger(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    KThSmallestRemainingEvenIntegerInSubarrayQueriesTestSuite,
    KThSmallestRemainingEvenIntegerInSubarrayQueriesTest,
    ::testing::ValuesIn(
        KThSmallestRemainingEvenIntegerInSubarrayQueriesSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_3911
}  // namespace leetcode
