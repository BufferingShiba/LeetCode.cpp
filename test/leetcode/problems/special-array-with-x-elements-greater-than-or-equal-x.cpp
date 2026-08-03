#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/special-array-with-x-elements-greater-than-or-equal-x.h"

namespace leetcode {
namespace problem_1608 {

using SpecialArrayWithXElementsGreaterThanOrEqualXTest =
    ::testing::TestWithParam<std::string>;

class SpecialArrayWithXElementsGreaterThanOrEqualXFixture
    : public SpecialArrayWithXElementsGreaterThanOrEqualXTest {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SpecialArrayWithXElementsGreaterThanOrEqualXSolution solution;
};

TEST_P(SpecialArrayWithXElementsGreaterThanOrEqualXFixture, Example1) {
  std::vector<int> nums = {3, 5};
  EXPECT_EQ(solution.specialArray(nums), 2);
}

TEST_P(SpecialArrayWithXElementsGreaterThanOrEqualXFixture, Example2) {
  std::vector<int> nums = {0, 0};
  EXPECT_EQ(solution.specialArray(nums), -1);
}

TEST_P(SpecialArrayWithXElementsGreaterThanOrEqualXFixture, Example3) {
  std::vector<int> nums = {0, 4, 3, 0, 4};
  EXPECT_EQ(solution.specialArray(nums), 3);
}

TEST_P(SpecialArrayWithXElementsGreaterThanOrEqualXFixture, SelfAuthoredSingleElementMatching) {
  std::vector<int> nums = {0};
  EXPECT_EQ(solution.specialArray(nums), -1);
}

TEST_P(SpecialArrayWithXElementsGreaterThanOrEqualXFixture, SelfAuthoredSingleBigElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.specialArray(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    SpecialArrayWithXElementsGreaterThanOrEqualXTestSuite,
    SpecialArrayWithXElementsGreaterThanOrEqualXFixture,
    ::testing::ValuesIn(
        SpecialArrayWithXElementsGreaterThanOrEqualXSolution()
            .getStrategyNames()));

}  // namespace problem_1608
}  // namespace leetcode
