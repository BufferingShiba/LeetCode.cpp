#include <gtest/gtest.h>

#include "leetcode/problems/stone-game-ix.h"

namespace leetcode {
namespace problem_2029 {

class StoneGameIxTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  StoneGameIxSolution solution_;
};

TEST_P(StoneGameIxTest, Example1) {
  std::vector<int> stones = {2, 1};
  EXPECT_TRUE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, Example2) {
  std::vector<int> stones = {2};
  EXPECT_FALSE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, Example3) {
  std::vector<int> stones = {5, 1, 2, 4, 3};
  EXPECT_FALSE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, SelfAuthoredAllZerosEven) {
  std::vector<int> stones = {3, 6, 9, 12};
  EXPECT_FALSE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, SelfAuthoredSingleOne) {
  std::vector<int> stones = {1};
  EXPECT_FALSE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, SelfAuthoredSingleZero) {
  std::vector<int> stones = {3};
  EXPECT_FALSE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, SelfAuthoredBothTypesEvenC0) {
  std::vector<int> stones = {1, 1, 2};
  EXPECT_TRUE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, SelfAuthoredOddC0DiffGt2) {
  // c0=1, c1=0, c2=5 → |0-5|=5 > 2 → Alice wins
  std::vector<int> stones = {3, 2, 2, 2, 2, 2};
  EXPECT_TRUE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, SelfAuthoredOddC0DiffEq2) {
  // c0=1, c1=0, c2=3 → |0-3|=3 > 2 → Alice wins
  // Actually |0-3|=3 > 2, so Alice wins.
  std::vector<int> stones = {3, 2, 2, 2};
  EXPECT_TRUE(solution_.stoneGameIX(stones));
}

TEST_P(StoneGameIxTest, SelfAuthoredOddC0DiffLe2) {
  // c0=1, c1=0, c2=2 → |0-2|=2, not >2 → Bob wins
  std::vector<int> stones = {3, 2, 2};
  EXPECT_FALSE(solution_.stoneGameIX(stones));
}

INSTANTIATE_TEST_SUITE_P(Strategies, StoneGameIxTest,
                         ::testing::ValuesIn(StoneGameIxSolution().getStrategyNames()));

}  // namespace problem_2029
}  // namespace leetcode
