#include "leetcode/problems/count-triplets-that-can-form-two-arrays-of-equal-xor.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1442 {

class CountTripletsThatCanFormTwoArraysOfEqualXorTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountTripletsThatCanFormTwoArraysOfEqualXorSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  arr = [2,3,1,6,7]
// Output: 4
TEST_P(CountTripletsThatCanFormTwoArraysOfEqualXorTest, OfficialExample1) {
  std::vector<int> arr = {2, 3, 1, 6, 7};
  int result = solution.countTriplets(arr);
  EXPECT_EQ(4, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  arr = [1,1,1,1,1]
// Output: 10
TEST_P(CountTripletsThatCanFormTwoArraysOfEqualXorTest, OfficialExample2) {
  std::vector<int> arr = {1, 1, 1, 1, 1};
  int result = solution.countTriplets(arr);
  EXPECT_EQ(10, result);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountTripletsThatCanFormTwoArraysOfEqualXorTest,
    ::testing::ValuesIn(CountTripletsThatCanFormTwoArraysOfEqualXorSolution().getStrategyNames()));

}  // namespace problem_1442
}  // namespace leetcode
