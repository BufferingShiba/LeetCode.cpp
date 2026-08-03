#include "leetcode/problems/maximum-bags-with-full-capacity-of-rocks.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_2279::test {

class MaximumBagsWithFullCapacityOfRocksTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumBagsWithFullCapacityOfRocksSolution solution_;
};

TEST_P(MaximumBagsWithFullCapacityOfRocksTest, Example1) {
  std::vector<int> capacity = {2, 3, 4, 5};
  std::vector<int> rocks = {1, 2, 4, 4};
  ASSERT_EQ(solution_.maximumBags(capacity, rocks, 2), 3);
}

TEST_P(MaximumBagsWithFullCapacityOfRocksTest, Example2) {
  std::vector<int> capacity = {10, 2, 2};
  std::vector<int> rocks = {2, 2, 0};
  ASSERT_EQ(solution_.maximumBags(capacity, rocks, 100), 3);
}

TEST_P(MaximumBagsWithFullCapacityOfRocksTest, SelfAuthoredSingleBagAlreadyFull) {
  std::vector<int> capacity = {5};
  std::vector<int> rocks = {5};
  ASSERT_EQ(solution_.maximumBags(capacity, rocks, 1), 1);
}

TEST_P(MaximumBagsWithFullCapacityOfRocksTest, SelfAuthoredNoEnoughRocksForAnyBag) {
  std::vector<int> capacity = {10, 10, 10};
  std::vector<int> rocks = {0, 0, 0};
  ASSERT_EQ(solution_.maximumBags(capacity, rocks, 9), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumBagsWithFullCapacityOfRocksSuite,
    MaximumBagsWithFullCapacityOfRocksTest,
    testing::ValuesIn(
        MaximumBagsWithFullCapacityOfRocksSolution().getStrategyNames()));

}  // namespace leetcode::problem_2279::test
