#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/lexicographically-smallest-string-after-applying-operations.h"

namespace leetcode {
namespace problem_1625 {

class LexicographicallySmallestStringAfterApplyingOperationsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  LexicographicallySmallestStringAfterApplyingOperationsSolution solution_;
};

TEST_P(LexicographicallySmallestStringAfterApplyingOperationsTest, Example1) {
  std::string s = "5525";
  int a = 9;
  int b = 2;
  std::string expected = "2050";
  EXPECT_EQ(solution_.findLexSmallestString(s, a, b), expected);
}

TEST_P(LexicographicallySmallestStringAfterApplyingOperationsTest, Example2) {
  std::string s = "74";
  int a = 5;
  int b = 1;
  std::string expected = "24";
  EXPECT_EQ(solution_.findLexSmallestString(s, a, b), expected);
}

TEST_P(LexicographicallySmallestStringAfterApplyingOperationsTest, Example3) {
  std::string s = "0011";
  int a = 4;
  int b = 2;
  std::string expected = "0011";
  EXPECT_EQ(solution_.findLexSmallestString(s, a, b), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    LexicographicallySmallestStringAfterApplyingOperationsTest,
    testing::ValuesIn(
        LexicographicallySmallestStringAfterApplyingOperationsSolution()
            .getStrategyNames()));

}  // namespace problem_1625
}  // namespace leetcode
