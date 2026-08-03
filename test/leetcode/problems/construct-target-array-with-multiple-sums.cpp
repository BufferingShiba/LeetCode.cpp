#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/construct-target-array-with-multiple-sums.h"

namespace leetcode::problem_1354 {

class ConstructTargetArrayWithMultipleSumsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConstructTargetArrayWithMultipleSumsSolution solution_;
};

TEST_P(ConstructTargetArrayWithMultipleSumsTest, Example1) {
  std::vector<int> target{9, 3, 5};
  EXPECT_TRUE(solution_.isPossible(target));
}

TEST_P(ConstructTargetArrayWithMultipleSumsTest, Example2) {
  std::vector<int> target{1, 1, 1, 2};
  EXPECT_FALSE(solution_.isPossible(target));
}

TEST_P(ConstructTargetArrayWithMultipleSumsTest, Example3) {
  std::vector<int> target{8, 5};
  EXPECT_TRUE(solution_.isPossible(target));
}

TEST_P(ConstructTargetArrayWithMultipleSumsTest, SelfAuthoredSingleElement) {
  std::vector<int> target{1};
  EXPECT_TRUE(solution_.isPossible(target));
}

TEST_P(ConstructTargetArrayWithMultipleSumsTest, SelfAuthoredSingleElementNotOne) {
  std::vector<int> target{3};
  EXPECT_FALSE(solution_.isPossible(target));
}

TEST_P(ConstructTargetArrayWithMultipleSumsTest, SelfAuthoredAllOnes) {
  std::vector<int> target{1, 1, 1};
  EXPECT_TRUE(solution_.isPossible(target));
}

TEST_P(ConstructTargetArrayWithMultipleSumsTest, SelfAuthoredLargeNumbers) {
  std::vector<int> target{4, 7, 11};
  EXPECT_FALSE(solution_.isPossible(target));
}

INSTANTIATE_TEST_SUITE_P(
    ConstructTargetArrayWithMultipleSumsTestSuite,
    ConstructTargetArrayWithMultipleSumsTest,
    ::testing::ValuesIn(
        ConstructTargetArrayWithMultipleSumsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1354
