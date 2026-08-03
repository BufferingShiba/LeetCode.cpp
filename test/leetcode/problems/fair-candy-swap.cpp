#include <gtest/gtest.h>

#include "leetcode/problems/fair-candy-swap.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_888 {
namespace {

class FairCandySwapTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FairCandySwapSolution solution_;
};

TEST_P(FairCandySwapTest, Example1) {
  std::vector<int> aliceSizes = {1, 1};
  std::vector<int> bobSizes = {2, 2};
  std::vector<int> result = solution_.fairCandySwap(aliceSizes, bobSizes);
  EXPECT_EQ(result.size(), 2u);
  EXPECT_EQ(result[0], 1);
  EXPECT_EQ(result[1], 2);
}

TEST_P(FairCandySwapTest, Example2) {
  std::vector<int> aliceSizes = {1, 2};
  std::vector<int> bobSizes = {2, 3};
  std::vector<int> result = solution_.fairCandySwap(aliceSizes, bobSizes);
  EXPECT_EQ(result.size(), 2u);
  EXPECT_EQ(result[0], 1);
  EXPECT_EQ(result[1], 2);
}

TEST_P(FairCandySwapTest, Example3) {
  std::vector<int> aliceSizes = {2};
  std::vector<int> bobSizes = {1, 3};
  std::vector<int> result = solution_.fairCandySwap(aliceSizes, bobSizes);
  EXPECT_EQ(result.size(), 2u);
  EXPECT_EQ(result[0], 2);
  EXPECT_EQ(result[1], 3);
}

TEST_P(FairCandySwapTest, SelfAuthoredSingleElementEach) {
  std::vector<int> aliceSizes = {4};
  std::vector<int> bobSizes = {2, 6};
  std::vector<int> result = solution_.fairCandySwap(aliceSizes, bobSizes);
  EXPECT_EQ(result.size(), 2u);
  EXPECT_EQ(result[0], 4);
  EXPECT_EQ(result[1], 6);
}

INSTANTIATE_TEST_SUITE_P(FairCandySwapTestSuite, FairCandySwapTest,
                         ::testing::ValuesIn(FairCandySwapSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_888
}  // namespace leetcode
