#include <gtest/gtest.h>
#include "leetcode/problems/find-all-good-indices.h"

namespace leetcode {
namespace problem_2420 {

class FindAllGoodIndicesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  FindAllGoodIndicesSolution solution_;
};

TEST_P(FindAllGoodIndicesTest, Example1) {
  std::vector<int> nums = {2, 1, 1, 1, 3, 4, 1};
  int k = 2;
  std::vector<int> expected = {2, 3};
  EXPECT_EQ(solution_.goodIndices(nums, k), expected);
}

TEST_P(FindAllGoodIndicesTest, Example2) {
  std::vector<int> nums = {2, 1, 1, 2};
  int k = 2;
  std::vector<int> expected = {};
  EXPECT_EQ(solution_.goodIndices(nums, k), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindAllGoodIndicesTest,
    testing::ValuesIn(FindAllGoodIndicesSolution().getStrategyNames()));

}  // namespace problem_2420
}  // namespace leetcode
