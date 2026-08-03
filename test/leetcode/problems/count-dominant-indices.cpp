#include "leetcode/problems/count-dominant-indices.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_3833 {

class CountDominantIndicesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountDominantIndicesSolution solution_;
};

TEST_P(CountDominantIndicesTest, Example1) {
  std::vector<int> nums{5, 4, 3};
  EXPECT_EQ(solution_.dominantIndices(nums), 2);
}

TEST_P(CountDominantIndicesTest, Example2) {
  std::vector<int> nums{4, 1, 2};
  EXPECT_EQ(solution_.dominantIndices(nums), 1);
}

TEST_P(CountDominantIndicesTest, SingleElement) {
  std::vector<int> nums{7};
  EXPECT_EQ(solution_.dominantIndices(nums), 0);
}

TEST_P(CountDominantIndicesTest, AllEqual) {
  std::vector<int> nums{3, 3, 3};
  // i=0: 3 vs avg(3,3)=3 -> not dominant; i=1: 3 vs avg(3)=3 -> not dominant
  EXPECT_EQ(solution_.dominantIndices(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountDominantIndicesTestSuite, CountDominantIndicesTest,
    ::testing::ValuesIn(CountDominantIndicesSolution().getStrategyNames()));

}  // namespace leetcode::problem_3833
