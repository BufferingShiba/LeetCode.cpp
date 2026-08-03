#include <gtest/gtest.h>

#include "leetcode/problems/make-two-arrays-equal-by-reversing-subarrays.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1460 {
namespace {

using MakeTwoArraysEqualByReversingSubarraysTest =
    ::testing::TestWithParam<std::string>;

class MakeTwoArraysEqualByReversingSubarraysFixture
    : public MakeTwoArraysEqualByReversingSubarraysTest {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MakeTwoArraysEqualByReversingSubarraysSolution solution_;
};

TEST_P(MakeTwoArraysEqualByReversingSubarraysFixture, Example1) {
  std::vector<int> target = {1, 2, 3, 4};
  std::vector<int> arr = {2, 4, 1, 3};
  EXPECT_TRUE(solution_.canBeEqual(target, arr));
}

TEST_P(MakeTwoArraysEqualByReversingSubarraysFixture, Example2) {
  std::vector<int> target = {7};
  std::vector<int> arr = {7};
  EXPECT_TRUE(solution_.canBeEqual(target, arr));
}

TEST_P(MakeTwoArraysEqualByReversingSubarraysFixture, Example3) {
  std::vector<int> target = {3, 7, 9};
  std::vector<int> arr = {3, 7, 11};
  EXPECT_FALSE(solution_.canBeEqual(target, arr));
}

TEST_P(MakeTwoArraysEqualByReversingSubarraysFixture, SelfAuthored_SameMultiset) {
  std::vector<int> target = {5, 1, 5};
  std::vector<int> arr = {5, 5, 1};
  EXPECT_TRUE(solution_.canBeEqual(target, arr));
}

TEST_P(MakeTwoArraysEqualByReversingSubarraysFixture, SelfAuthored_DiffElementCount) {
  std::vector<int> target = {1, 2};
  std::vector<int> arr = {1, 3};
  EXPECT_FALSE(solution_.canBeEqual(target, arr));
}

INSTANTIATE_TEST_SUITE_P(
    MakeTwoArraysEqualByReversingSubarraysTestSuite,
    MakeTwoArraysEqualByReversingSubarraysFixture,
    ::testing::ValuesIn(
        MakeTwoArraysEqualByReversingSubarraysSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1460
}  // namespace leetcode
