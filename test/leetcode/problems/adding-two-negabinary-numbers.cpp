#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/adding-two-negabinary-numbers.h"

namespace leetcode {
namespace problem_1073 {

class AddingTwoNegabinaryNumbersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  AddingTwoNegabinaryNumbersSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(AddingTwoNegabinaryNumbersTest, Example1) {
  std::vector<int> arr1 = {1, 1, 1, 1, 1};
  std::vector<int> arr2 = {1, 0, 1};
  std::vector<int> expected = {1, 0, 0, 0, 0};
  EXPECT_EQ(solution.addNegabinary(arr1, arr2), expected);
}

TEST_P(AddingTwoNegabinaryNumbersTest, Example2) {
  std::vector<int> arr1 = {0};
  std::vector<int> arr2 = {0};
  std::vector<int> expected = {0};
  EXPECT_EQ(solution.addNegabinary(arr1, arr2), expected);
}

TEST_P(AddingTwoNegabinaryNumbersTest, Example3) {
  std::vector<int> arr1 = {0};
  std::vector<int> arr2 = {1};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.addNegabinary(arr1, arr2), expected);
}

INSTANTIATE_TEST_SUITE_P(
    AddingTwoNegabinaryNumbersStrategies, AddingTwoNegabinaryNumbersTest,
    ::testing::ValuesIn(AddingTwoNegabinaryNumbersSolution().getStrategyNames()));

}  // namespace problem_1073
}  // namespace leetcode
