#include "leetcode/problems/decompress-run-length-encoded-list.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1313 {
namespace {

class DecompressRunLengthEncodedListTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DecompressRunLengthEncodedListSolution solution_;
};

TEST_P(DecompressRunLengthEncodedListTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> expected = {2, 4, 4, 4};
  EXPECT_EQ(expected, solution_.decompressRLElist(nums));
}

TEST_P(DecompressRunLengthEncodedListTest, Example2) {
  std::vector<int> nums = {1, 1, 2, 3};
  std::vector<int> expected = {1, 3, 3};
  EXPECT_EQ(expected, solution_.decompressRLElist(nums));
}

TEST_P(DecompressRunLengthEncodedListTest, SelfAuthoredSinglePair) {
  std::vector<int> nums = {4, 7};
  std::vector<int> expected = {7, 7, 7, 7};
  EXPECT_EQ(expected, solution_.decompressRLElist(nums));
}

TEST_P(DecompressRunLengthEncodedListTest, SelfAuthoredFrequencyOne) {
  std::vector<int> nums = {1, 5, 1, 9, 1, 2};
  std::vector<int> expected = {5, 9, 2};
  EXPECT_EQ(expected, solution_.decompressRLElist(nums));
}

INSTANTIATE_TEST_SUITE_P(
    DecompressRunLengthEncodedListStrategies, DecompressRunLengthEncodedListTest,
    ::testing::ValuesIn(DecompressRunLengthEncodedListSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1313
}  // namespace leetcode
