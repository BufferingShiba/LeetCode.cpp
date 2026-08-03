#include "leetcode/problems/check-if-n-and-its-double-exist.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1346 {
namespace {

class CheckIfNAndItsDoubleExistTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CheckIfNAndItsDoubleExistSolution solution_;
};

TEST_P(CheckIfNAndItsDoubleExistTest, Example1) {
  std::vector<int> arr{10, 2, 5, 3};
  EXPECT_TRUE(solution_.checkIfExist(arr));
}

TEST_P(CheckIfNAndItsDoubleExistTest, Example2) {
  std::vector<int> arr{3, 1, 7, 11};
  EXPECT_FALSE(solution_.checkIfExist(arr));
}

TEST_P(CheckIfNAndItsDoubleExistTest, ZeroPair) {
  std::vector<int> arr{0, 0};
  EXPECT_TRUE(solution_.checkIfExist(arr));
}

TEST_P(CheckIfNAndItsDoubleExistTest, NegativeDouble) {
  std::vector<int> arr{-8, 4, 2, -4};
  EXPECT_TRUE(solution_.checkIfExist(arr));
}

TEST_P(CheckIfNAndItsDoubleExistTest, NegativeNoMatch) {
  std::vector<int> arr{3, 1, 7, 11};
  EXPECT_FALSE(solution_.checkIfExist(arr));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfNAndItsDoubleExistTestSuite, CheckIfNAndItsDoubleExistTest,
    ::testing::ValuesIn(CheckIfNAndItsDoubleExistSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1346
}  // namespace leetcode
