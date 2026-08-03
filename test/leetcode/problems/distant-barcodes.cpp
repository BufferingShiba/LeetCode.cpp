#include <gtest/gtest.h>

#include <unordered_map>

#include "leetcode/problems/distant-barcodes.h"

using namespace leetcode::problem_1054;

class DistantBarcodesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DistantBarcodesSolution solution;
};

TEST_P(DistantBarcodesTest, Example1) {
  std::vector<int> barcodes = {1, 1, 1, 2, 2, 2};
  auto result = solution.rearrangeBarcodes(barcodes);

  // 验证相邻不同
  for (size_t i = 1; i < result.size(); ++i) {
    EXPECT_NE(result[i], result[i - 1]);
  }

  // 验证元素计数一致
  std::unordered_map<int, int> input_count, result_count;
  for (int b : barcodes) input_count[b]++;
  for (int b : result) result_count[b]++;
  EXPECT_EQ(input_count, result_count);
}

TEST_P(DistantBarcodesTest, Example2) {
  std::vector<int> barcodes = {1, 1, 1, 1, 2, 2, 3, 3};
  auto result = solution.rearrangeBarcodes(barcodes);

  for (size_t i = 1; i < result.size(); ++i) {
    EXPECT_NE(result[i], result[i - 1]);
  }

  std::unordered_map<int, int> input_count, result_count;
  for (int b : barcodes) input_count[b]++;
  for (int b : result) result_count[b]++;
  EXPECT_EQ(input_count, result_count);
}

TEST_P(DistantBarcodesTest, SelfAuthoredSingleElement) {
  std::vector<int> barcodes = {5};
  auto result = solution.rearrangeBarcodes(barcodes);
  EXPECT_EQ(result.size(), 1u);
  EXPECT_EQ(result[0], 5);
}

TEST_P(DistantBarcodesTest, SelfAuthoredTwoDifferent) {
  std::vector<int> barcodes = {1, 2};
  auto result = solution.rearrangeBarcodes(barcodes);
  EXPECT_EQ(result.size(), 2u);
  EXPECT_NE(result[0], result[1]);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    DistantBarcodesTest,
    testing::ValuesIn(DistantBarcodesSolution().getStrategyNames()));
