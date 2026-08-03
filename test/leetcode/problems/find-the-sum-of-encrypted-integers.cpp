#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-sum-of-encrypted-integers.h"

namespace leetcode {
namespace problem_3079 {

class FindTheSumOfEncryptedIntegersTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindTheSumOfEncryptedIntegersSolution solution_;
};

TEST_P(FindTheSumOfEncryptedIntegersTest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution_.sumOfEncryptedInt(nums), 6);
}

TEST_P(FindTheSumOfEncryptedIntegersTest, Example2) {
  std::vector<int> nums = {10, 21, 31};
  EXPECT_EQ(solution_.sumOfEncryptedInt(nums), 66);
}

TEST_P(FindTheSumOfEncryptedIntegersTest, SelfAuthoredSingleDigit) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution_.sumOfEncryptedInt(nums), 5);
}

TEST_P(FindTheSumOfEncryptedIntegersTest, SelfAuthoredFourDigits) {
  std::vector<int> nums = {1000};
  EXPECT_EQ(solution_.sumOfEncryptedInt(nums), 1111);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheSumOfEncryptedIntegersTests,
    FindTheSumOfEncryptedIntegersTest,
    ::testing::ValuesIn(
        FindTheSumOfEncryptedIntegersSolution().getStrategyNames()));

}  // namespace problem_3079
}  // namespace leetcode
