#include "leetcode/problems/make-lexicographically-smallest-array-by-swapping-elements.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2948 {

class MakeLexicographicallySmallestArrayBySwappingElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MakeLexicographicallySmallestArrayBySwappingElementsSolution solution_;
};

TEST_P(MakeLexicographicallySmallestArrayBySwappingElementsTest, Example1) {
  std::vector<int> nums = {1, 5, 3, 9, 8};
  int limit = 2;
  std::vector<int> expected = {1, 3, 5, 8, 9};
  EXPECT_EQ(solution_.lexicographicallySmallestArray(nums, limit), expected);
}

TEST_P(MakeLexicographicallySmallestArrayBySwappingElementsTest, Example2) {
  std::vector<int> nums = {1, 7, 6, 18, 2, 1};
  int limit = 3;
  std::vector<int> expected = {1, 6, 7, 18, 1, 2};
  EXPECT_EQ(solution_.lexicographicallySmallestArray(nums, limit), expected);
}

TEST_P(MakeLexicographicallySmallestArrayBySwappingElementsTest, Example3) {
  std::vector<int> nums = {1, 7, 28, 19, 10};
  int limit = 3;
  std::vector<int> expected = {1, 7, 28, 19, 10};
  EXPECT_EQ(solution_.lexicographicallySmallestArray(nums, limit), expected);
}

TEST_P(MakeLexicographicallySmallestArrayBySwappingElementsTest,
       SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  int limit = 1;
  std::vector<int> expected = {5};
  EXPECT_EQ(solution_.lexicographicallySmallestArray(nums, limit), expected);
}

TEST_P(MakeLexicographicallySmallestArrayBySwappingElementsTest,
       SelfAuthoredAllSwappable) {
  std::vector<int> nums = {3, 1, 2};
  int limit = 5;
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(solution_.lexicographicallySmallestArray(nums, limit), expected);
}

TEST_P(MakeLexicographicallySmallestArrayBySwappingElementsTest,
       SelfAuthoredNoSwapPossible) {
  std::vector<int> nums = {1, 100, 50};
  int limit = 1;
  std::vector<int> expected = {1, 100, 50};
  EXPECT_EQ(solution_.lexicographicallySmallestArray(nums, limit), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MakeLexicographicallySmallestArrayBySwappingElementsTestCases,
    MakeLexicographicallySmallestArrayBySwappingElementsTest,
    ::testing::ValuesIn(
        MakeLexicographicallySmallestArrayBySwappingElementsSolution()
            .getStrategyNames()));

}  // namespace problem_2948
}  // namespace leetcode
