#include <gtest/gtest.h>

#include "leetcode/problems/can-place-flowers.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_605 {

class CanPlaceFlowersTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CanPlaceFlowersSolution solution;
};

TEST_P(CanPlaceFlowersTest, Example1) {
  std::vector<int> flowerbed{1, 0, 0, 0, 1};
  EXPECT_TRUE(solution.canPlaceFlowers(flowerbed, 1));
}

TEST_P(CanPlaceFlowersTest, Example2) {
  std::vector<int> flowerbed{1, 0, 0, 0, 1};
  EXPECT_FALSE(solution.canPlaceFlowers(flowerbed, 2));
}

TEST_P(CanPlaceFlowersTest, SelfAuthoredAllEmpty) {
  std::vector<int> flowerbed{0, 0, 0, 0, 0};
  EXPECT_TRUE(solution.canPlaceFlowers(flowerbed, 3));
}

TEST_P(CanPlaceFlowersTest, SelfAuthoredSinglePlot) {
  std::vector<int> flowerbed{0};
  EXPECT_TRUE(solution.canPlaceFlowers(flowerbed, 1));
}

TEST_P(CanPlaceFlowersTest, SelfAuthoredZeroNeeded) {
  std::vector<int> flowerbed{1, 0, 0, 0, 1};
  EXPECT_TRUE(solution.canPlaceFlowers(flowerbed, 0));
}

INSTANTIATE_TEST_SUITE_P(
    CanPlaceFlowersTestSuite, CanPlaceFlowersTest,
    ::testing::ValuesIn(CanPlaceFlowersSolution().getStrategyNames()));

}  // namespace problem_605
}  // namespace leetcode
