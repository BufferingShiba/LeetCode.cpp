#include <gtest/gtest.h>

#include "leetcode/problems/find-lucky-integer-in-an-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1394 {
namespace test {

namespace {

class FindLuckyIntegerInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  FindLuckyIntegerInAnArraySolution solution;
};

}  // namespace

TEST_P(FindLuckyIntegerInAnArrayTest, Example1) {
  std::vector<int> arr = {2, 2, 3, 4};
  EXPECT_EQ(2, solution.findLucky(arr));
}

TEST_P(FindLuckyIntegerInAnArrayTest, Example2) {
  std::vector<int> arr = {1, 2, 2, 3, 3, 3};
  EXPECT_EQ(3, solution.findLucky(arr));
}

TEST_P(FindLuckyIntegerInAnArrayTest, Example3) {
  std::vector<int> arr = {2, 2, 2, 3, 3};
  EXPECT_EQ(-1, solution.findLucky(arr));
}

TEST_P(FindLuckyIntegerInAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> arr = {1};
  EXPECT_EQ(1, solution.findLucky(arr));
}

TEST_P(FindLuckyIntegerInAnArrayTest, SelfAuthoredSingleElementNotLucky) {
  std::vector<int> arr = {5};
  EXPECT_EQ(-1, solution.findLucky(arr));
}

INSTANTIATE_TEST_SUITE_P(
    FindLuckyIntegerInAnArrayTestSuite,
    FindLuckyIntegerInAnArrayTest,
    ::testing::ValuesIn(FindLuckyIntegerInAnArraySolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_1394
}  // namespace leetcode
