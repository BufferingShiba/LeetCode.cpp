#include "leetcode/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues.h"

#include <gtest/gtest.h>

using leetcode::problem_3572::MaximizeYsumByPickingATripletOfDistinctXvaluesSolution;

namespace leetcode {
namespace problem_3572 {
namespace {

class MaximizeYsumByPickingATripletOfDistinctXvaluesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximizeYsumByPickingATripletOfDistinctXvaluesSolution solution_;
};

TEST_P(MaximizeYsumByPickingATripletOfDistinctXvaluesTest, Example1) {
  std::vector<int> x{1, 2, 1, 3, 2};
  std::vector<int> y{5, 3, 4, 6, 2};
  EXPECT_EQ(14, solution_.maxSumDistinctTriplet(x, y));
}

TEST_P(MaximizeYsumByPickingATripletOfDistinctXvaluesTest, Example2) {
  std::vector<int> x{1, 2, 1, 2};
  std::vector<int> y{4, 5, 6, 7};
  EXPECT_EQ(-1, solution_.maxSumDistinctTriplet(x, y));
}

TEST_P(MaximizeYsumByPickingATripletOfDistinctXvaluesTest, SelfAuthoredExactlyThreeDistinct) {
  std::vector<int> x{1, 2, 3, 1, 2, 3};
  std::vector<int> y{10, 1, 1, 1, 9, 8};
  // x=1 max 10, x=2 max 9, x=3 max 8 -> 27
  EXPECT_EQ(27, solution_.maxSumDistinctTriplet(x, y));
}

TEST_P(MaximizeYsumByPickingATripletOfDistinctXvaluesTest, SelfAuthoredTwoDistinctValues) {
  std::vector<int> x{5, 5, 7, 5, 7};
  std::vector<int> y{1, 2, 3, 4, 5};
  EXPECT_EQ(-1, solution_.maxSumDistinctTriplet(x, y));
}

INSTANTIATE_TEST_SUITE_P(
    MaximizeYsumByPickingATripletOfDistinctXvaluesTestInstantiation,
    MaximizeYsumByPickingATripletOfDistinctXvaluesTest,
    ::testing::ValuesIn(
        MaximizeYsumByPickingATripletOfDistinctXvaluesSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_3572
}  // namespace leetcode
