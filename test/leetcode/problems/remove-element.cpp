#include "leetcode/problems/remove-element.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_27 {
namespace {

using testing::TestWithParam;
using testing::ValuesIn;

}  // namespace

class RemoveElementTest : public TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  RemoveElementSolution solution_;
};

TEST_P(RemoveElementTest, Example1) {
  std::vector<int> nums{3, 2, 2, 3};
  int val = 3;
  int k = solution_.removeElement(nums, val);
  ASSERT_EQ(k, 2);
  ASSERT_EQ(nums[0], 2);
  ASSERT_EQ(nums[1], 2);
}

TEST_P(RemoveElementTest, Example2) {
  std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  int k = solution_.removeElement(nums, val);
  ASSERT_EQ(k, 5);
  // The order may change, so verify order-independently.
  std::vector<int> expected{0, 1, 4, 0, 3};
  std::vector<int> actual(nums.begin(), nums.begin() + k);
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  ASSERT_EQ(actual, expected);
}

TEST_P(RemoveElementTest, NoOccurrence) {
  std::vector<int> nums{1, 2, 3, 4};
  int val = 10;
  int k = solution_.removeElement(nums, val);
  ASSERT_EQ(k, 4);
  ASSERT_EQ(nums[0], 1);
  ASSERT_EQ(nums[1], 2);
  ASSERT_EQ(nums[2], 3);
  ASSERT_EQ(nums[3], 4);
}

INSTANTIATE_TEST_SUITE_P(RemoveElementTestSuite, RemoveElementTest,
                         ValuesIn(RemoveElementSolution().getStrategyNames()));

}  // namespace problem_27
}  // namespace leetcode
