#include "leetcode/problems/find-indices-of-stable-mountains.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3285 {

class FindIndicesOfStableMountainsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindIndicesOfStableMountainsSolution solution_;
};

TEST_P(FindIndicesOfStableMountainsTest, Example1) {
  std::vector<int> height{1, 2, 3, 4, 5};
  std::vector<int> expected{3, 4};
  EXPECT_EQ(solution_.stableMountains(height, 2), expected);
}

TEST_P(FindIndicesOfStableMountainsTest, Example2) {
  std::vector<int> height{10, 1, 10, 1, 10};
  std::vector<int> expected{1, 3};
  EXPECT_EQ(solution_.stableMountains(height, 3), expected);
}

TEST_P(FindIndicesOfStableMountainsTest, Example3) {
  std::vector<int> height{10, 1, 10, 1, 10};
  std::vector<int> expected{};
  EXPECT_EQ(solution_.stableMountains(height, 10), expected);
}

TEST_P(FindIndicesOfStableMountainsTest, SelfAuthoredThresholdHigherThanAllPrev) {
  std::vector<int> height{1, 1, 1, 1};
  std::vector<int> expected{1, 2, 3};
  EXPECT_EQ(solution_.stableMountains(height, 0), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindIndicesOfStableMountainsTestSuite,
    FindIndicesOfStableMountainsTest,
    ::testing::ValuesIn(FindIndicesOfStableMountainsSolution().getStrategyNames()));

}  // namespace problem_3285
}  // namespace leetcode
