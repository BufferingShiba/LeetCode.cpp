#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/kth-distinct-string-in-an-array.h"

namespace leetcode {
namespace problem_2053 {

class KthDistinctStringInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  KthDistinctStringInAnArraySolution solution_;
};

TEST_P(KthDistinctStringInAnArrayTest, Example1) {
  std::vector<std::string> arr = {"d", "b", "c", "b", "c", "a"};
  EXPECT_EQ(solution_.kthDistinct(arr, 2), "a");
}

TEST_P(KthDistinctStringInAnArrayTest, Example2) {
  std::vector<std::string> arr = {"aaa", "aa", "a"};
  EXPECT_EQ(solution_.kthDistinct(arr, 1), "aaa");
}

TEST_P(KthDistinctStringInAnArrayTest, Example3) {
  std::vector<std::string> arr = {"a", "b", "a"};
  EXPECT_EQ(solution_.kthDistinct(arr, 3), "");
}

TEST_P(KthDistinctStringInAnArrayTest, SelfAuthoredKGreaterThanDistinct) {
  std::vector<std::string> arr = {"x", "y", "x", "z"};
  EXPECT_EQ(solution_.kthDistinct(arr, 2), "z");
  EXPECT_EQ(solution_.kthDistinct(arr, 3), "");
}

INSTANTIATE_TEST_SUITE_P(
    KthDistinctStringInAnArrayTestSuite,
    KthDistinctStringInAnArrayTest,
    ::testing::ValuesIn(
        KthDistinctStringInAnArraySolution().getStrategyNames()));

}  // namespace problem_2053
}  // namespace leetcode
