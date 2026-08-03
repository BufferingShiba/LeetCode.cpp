#include <gtest/gtest.h>
#include "leetcode/problems/three-equal-parts.h"

using namespace leetcode::problem_927;

class ThreeEqualPartsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ThreeEqualPartsSolution solution;
};

TEST_P(ThreeEqualPartsTest, Example1) {
  std::vector<int> arr = {1, 0, 1, 0, 1};
  auto result = solution.threeEqualParts(arr);
  EXPECT_EQ(result, std::vector<int>({0, 3}));
}

TEST_P(ThreeEqualPartsTest, Example2) {
  std::vector<int> arr = {1, 1, 0, 1, 1};
  auto result = solution.threeEqualParts(arr);
  EXPECT_EQ(result, std::vector<int>({-1, -1}));
}

TEST_P(ThreeEqualPartsTest, Example3) {
  std::vector<int> arr = {1, 1, 0, 0, 1};
  auto result = solution.threeEqualParts(arr);
  EXPECT_EQ(result, std::vector<int>({0, 2}));
}

TEST_P(ThreeEqualPartsTest, SelfAuthoredAllZeros) {
  std::vector<int> arr = {0, 0, 0, 0, 0};
  auto result = solution.threeEqualParts(arr);
  EXPECT_EQ(result, std::vector<int>({0, 2}));
}

TEST_P(ThreeEqualPartsTest, SelfAuthoredLeadingZerosInParts) {
  std::vector<int> arr = {0, 1, 0, 0, 1, 0, 0, 1, 0};
  auto result = solution.threeEqualParts(arr);
  EXPECT_EQ(result, std::vector<int>({2, 6}));
}

TEST_P(ThreeEqualPartsTest, SelfAuthoredImpossibleOddOnes) {
  std::vector<int> arr = {1, 0, 1, 1, 0};
  auto result = solution.threeEqualParts(arr);
  EXPECT_EQ(result, std::vector<int>({-1, -1}));
}

INSTANTIATE_TEST_SUITE_P(ThreeEqualParts, ThreeEqualPartsTest,
                         testing::ValuesIn(ThreeEqualPartsSolution()
                                               .getStrategyNames()));
