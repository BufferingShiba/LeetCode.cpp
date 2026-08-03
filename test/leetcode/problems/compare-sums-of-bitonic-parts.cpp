#include "leetcode/problems/compare-sums-of-bitonic-parts.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3909 {

class CompareSumsOfBitonicPartsTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  CompareSumsOfBitonicPartsSolution solution_;
};

TEST_P(CompareSumsOfBitonicPartsTest, Example1) {
  std::vector<int> nums{1, 3, 2, 1};
  EXPECT_EQ(1, solution_.compareBitonicSums(nums));
}

TEST_P(CompareSumsOfBitonicPartsTest, Example2) {
  std::vector<int> nums{2, 4, 5, 2};
  EXPECT_EQ(0, solution_.compareBitonicSums(nums));
}

TEST_P(CompareSumsOfBitonicPartsTest, Example3) {
  std::vector<int> nums{1, 2, 4, 3};
  EXPECT_EQ(-1, solution_.compareBitonicSums(nums));
}

INSTANTIATE_TEST_SUITE_P(
    CompareSumsOfBitonicPartsTestSuite, CompareSumsOfBitonicPartsTest,
    ::testing::ValuesIn(CompareSumsOfBitonicPartsSolution().getStrategyNames()));

}  // namespace problem_3909
}  // namespace leetcode
