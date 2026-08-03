#include <gtest/gtest.h>

#include "leetcode/problems/first-unique-even-element.h"

namespace leetcode {
namespace problem_3866 {

class FirstUniqueEvenElementTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FirstUniqueEvenElementSolution solution_;
};

TEST_P(FirstUniqueEvenElementTest, OfficialExamples) {
  std::vector<int> nums1 = {3, 4, 2, 5, 4, 6};
  EXPECT_EQ(solution_.firstUniqueEven(nums1), 2);

  std::vector<int> nums2 = {4, 4};
  EXPECT_EQ(solution_.firstUniqueEven(nums2), -1);
}

TEST_P(FirstUniqueEvenElementTest, SelfAuthored) {
  // 全部奇数
  std::vector<int> nums1 = {1, 3, 5, 7};
  EXPECT_EQ(solution_.firstUniqueEven(nums1), -1);

  // 只有一个偶数且出现多次
  std::vector<int> nums2 = {2, 2, 2};
  EXPECT_EQ(solution_.firstUniqueEven(nums2), -1);

  // 多个偶数，第一个唯一偶数在中间
  std::vector<int> nums3 = {2, 2, 4, 3, 6};
  EXPECT_EQ(solution_.firstUniqueEven(nums3), 4);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    FirstUniqueEvenElementTest,
    testing::ValuesIn(FirstUniqueEvenElementSolution().getStrategyNames()));

}  // namespace problem_3866
}  // namespace leetcode
