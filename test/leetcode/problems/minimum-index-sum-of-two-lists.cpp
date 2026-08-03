#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-index-sum-of-two-lists.h"

namespace leetcode {
namespace problem_599 {
namespace {

std::vector<std::string> expect2() {
  return {"Shogun"};
}

std::vector<std::string> expect3() {
  return {"sad", "happy"};
}

}  // namespace

class MinimumIndexSumOfTwoListsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumIndexSumOfTwoListsSolution solution;
};

TEST_P(MinimumIndexSumOfTwoListsTest, Example1) {
  std::vector<std::string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  std::vector<std::string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
  EXPECT_EQ(expect2(), solution.findRestaurant(list1, list2));
}

TEST_P(MinimumIndexSumOfTwoListsTest, Example2) {
  std::vector<std::string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  std::vector<std::string> list2 = {"KFC", "Shogun", "Burger King"};
  EXPECT_EQ(expect2(), solution.findRestaurant(list1, list2));
}

TEST_P(MinimumIndexSumOfTwoListsTest, Example3) {
  std::vector<std::string> list1 = {"happy", "sad", "good"};
  std::vector<std::string> list2 = {"sad", "happy", "good"};
  EXPECT_EQ(expect3(), solution.findRestaurant(list1, list2));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumIndexSumOfTwoListsStrategies, MinimumIndexSumOfTwoListsTest,
    ::testing::ValuesIn(MinimumIndexSumOfTwoListsSolution().getStrategyNames()));

}  // namespace problem_599
}  // namespace leetcode
