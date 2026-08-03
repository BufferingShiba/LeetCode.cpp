#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/remove-all-adjacent-duplicates-in-string.h"

namespace leetcode {
namespace problem_1047 {

using ::testing::TestWithParam;
using ::testing::Values;
using ::testing::ValuesIn;

class RemoveAllAdjacentDuplicatesInStringTest
    : public TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  RemoveAllAdjacentDuplicatesInStringSolution solution;
};

TEST_P(RemoveAllAdjacentDuplicatesInStringTest, Example1) {
  EXPECT_EQ(solution.removeDuplicates("abbaca"), "ca");
}

TEST_P(RemoveAllAdjacentDuplicatesInStringTest, Example2) {
  EXPECT_EQ(solution.removeDuplicates("azxxzy"), "ay");
}

TEST_P(RemoveAllAdjacentDuplicatesInStringTest, SelfAuthoredNoDuplicates) {
  EXPECT_EQ(solution.removeDuplicates("abcde"), "abcde");
}

TEST_P(RemoveAllAdjacentDuplicatesInStringTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.removeDuplicates("a"), "a");
}

INSTANTIATE_TEST_SUITE_P(
    RemoveAllAdjacentDuplicatesInStringTestSuite,
    RemoveAllAdjacentDuplicatesInStringTest,
    ValuesIn(RemoveAllAdjacentDuplicatesInStringSolution().getStrategyNames()));

}  // namespace problem_1047
}  // namespace leetcode
