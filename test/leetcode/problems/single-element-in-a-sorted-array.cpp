#include <gtest/gtest.h>

#include "leetcode/problems/single-element-in-a-sorted-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_540 {
namespace {

class SingleElementInASortedArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SingleElementInASortedArraySolution solution;
};

TEST_P(SingleElementInASortedArrayTest, Example1) {
  std::vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
  EXPECT_EQ(2, solution.singleNonDuplicate(nums));
}

TEST_P(SingleElementInASortedArrayTest, Example2) {
  std::vector<int> nums{3, 3, 7, 7, 10, 11, 11};
  EXPECT_EQ(10, solution.singleNonDuplicate(nums));
}

TEST_P(SingleElementInASortedArrayTest, SelfAuthoredSingleAtStart) {
  std::vector<int> nums{1, 2, 2, 3, 3};
  EXPECT_EQ(1, solution.singleNonDuplicate(nums));
}

TEST_P(SingleElementInASortedArrayTest, SelfAuthoredSingleAtEnd) {
  std::vector<int> nums{1, 1, 2, 2, 3};
  EXPECT_EQ(3, solution.singleNonDuplicate(nums));
}

TEST_P(SingleElementInASortedArrayTest, SelfAuthoredSingleLength) {
  std::vector<int> nums{7};
  EXPECT_EQ(7, solution.singleNonDuplicate(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SingleElementInASortedArrayTestSuite, SingleElementInASortedArrayTest,
    ::testing::ValuesIn(SingleElementInASortedArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_540
}  // namespace leetcode
