#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "leetcode/problems/two-out-of-three.h"

namespace leetcode {
namespace problem_2032 {

namespace {

void ExpectUnorderedEq(const std::vector<int>& expected, const std::vector<int>& actual) {
  EXPECT_EQ(expected.size(), actual.size());
  std::vector<int> a = expected;
  std::vector<int> b = actual;
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  EXPECT_EQ(a, b);
}

}  // namespace

class TwoOutOfThreeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  TwoOutOfThreeSolution solution;
};

TEST_P(TwoOutOfThreeTest, Example1) {
  std::vector<int> nums1{1, 1, 3, 2};
  std::vector<int> nums2{2, 3};
  std::vector<int> nums3{3};
  ExpectUnorderedEq({3, 2}, solution.twoOutOfThree(nums1, nums2, nums3));
}

TEST_P(TwoOutOfThreeTest, Example2) {
  std::vector<int> nums1{3, 1};
  std::vector<int> nums2{2, 3};
  std::vector<int> nums3{1, 2};
  ExpectUnorderedEq({2, 3, 1}, solution.twoOutOfThree(nums1, nums2, nums3));
}

TEST_P(TwoOutOfThreeTest, Example3) {
  std::vector<int> nums1{1, 2, 2};
  std::vector<int> nums2{4, 3, 3};
  std::vector<int> nums3{5};
  ExpectUnorderedEq({}, solution.twoOutOfThree(nums1, nums2, nums3));
}

TEST_P(TwoOutOfThreeTest, SelfAuthoredAllThree) {
  std::vector<int> nums1{7, 8};
  std::vector<int> nums2{8, 9};
  std::vector<int> nums3{9, 7};
  ExpectUnorderedEq({7, 8, 9}, solution.twoOutOfThree(nums1, nums2, nums3));
}

TEST_P(TwoOutOfThreeTest, SelfAuthoredOnlyOneArray) {
  std::vector<int> nums1{100, 99};
  std::vector<int> nums2{1, 2};
  std::vector<int> nums3{3, 4};
  ExpectUnorderedEq({}, solution.twoOutOfThree(nums1, nums2, nums3));
}

INSTANTIATE_TEST_SUITE_P(
    TwoOutOfThreeTestSuite, TwoOutOfThreeTest,
    ::testing::ValuesIn(TwoOutOfThreeSolution().getStrategyNames()));

}  // namespace problem_2032
}  // namespace leetcode
