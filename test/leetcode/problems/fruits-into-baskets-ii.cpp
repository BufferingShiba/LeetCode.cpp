#include "leetcode/problems/fruits-into-baskets-ii.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3477 {

class FruitsIntoBasketsIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FruitsIntoBasketsIiSolution solution;
};

TEST_P(FruitsIntoBasketsIiTest, Example1) {
  std::vector<int> fruits = {4, 2, 5};
  std::vector<int> baskets = {3, 5, 4};
  EXPECT_EQ(1, solution.numOfUnplacedFruits(fruits, baskets));
}

TEST_P(FruitsIntoBasketsIiTest, Example2) {
  std::vector<int> fruits = {3, 6, 1};
  std::vector<int> baskets = {6, 4, 7};
  EXPECT_EQ(0, solution.numOfUnplacedFruits(fruits, baskets));
}

TEST_P(FruitsIntoBasketsIiTest, SelfAuthoredAllPlaced) {
  std::vector<int> fruits = {1, 1, 1};
  std::vector<int> baskets = {1, 1, 1};
  EXPECT_EQ(0, solution.numOfUnplacedFruits(fruits, baskets));
}

TEST_P(FruitsIntoBasketsIiTest, SelfAuthoredAllUnplaced) {
  std::vector<int> fruits = {5, 5, 5};
  std::vector<int> baskets = {1, 2, 3};
  EXPECT_EQ(3, solution.numOfUnplacedFruits(fruits, baskets));
}

INSTANTIATE_TEST_SUITE_P(
    FruitsIntoBasketsIiTestSuite, FruitsIntoBasketsIiTest,
    ::testing::ValuesIn(FruitsIntoBasketsIiSolution().getStrategyNames()));

}  // namespace problem_3477
}  // namespace leetcode
