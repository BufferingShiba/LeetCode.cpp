#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "leetcode/problems/find-the-array-concatenation-value.h"

namespace leetcode {
namespace problem_2562 {
namespace {

class FindTheArrayConcatenationValueTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindTheArrayConcatenationValueSolution solution_;
};

TEST_P(FindTheArrayConcatenationValueTest, Example1) {
  std::vector<int> nums{7, 52, 2, 4};
  EXPECT_EQ(596, solution_.findTheArrayConcVal(nums));
}

TEST_P(FindTheArrayConcatenationValueTest, Example2) {
  std::vector<int> nums{5, 14, 13, 8, 12};
  EXPECT_EQ(673, solution_.findTheArrayConcVal(nums));
}

TEST_P(FindTheArrayConcatenationValueTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{42};
  EXPECT_EQ(42, solution_.findTheArrayConcVal(nums));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheArrayConcatenationValueTestSuite,
    FindTheArrayConcatenationValueTest,
    ::testing::ValuesIn(FindTheArrayConcatenationValueSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2562
}  // namespace leetcode
