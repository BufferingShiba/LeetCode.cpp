#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/lexicographically-smallest-string-after-substring-operation.h"

namespace leetcode::problem_2734 {

using LexicographicallySmallestStringAfterSubstringOperationTest =
    ::testing::TestWithParam<std::string>;

class LexicographicallySmallestStringAfterSubstringOperationTestFixture
    : public LexicographicallySmallestStringAfterSubstringOperationTest {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  LexicographicallySmallestStringAfterSubstringOperationSolution solution_;
};

static std::string run(const std::string& s,
                       LexicographicallySmallestStringAfterSubstringOperationSolution& sol) {
  return sol.smallestString(s);
}

TEST_P(LexicographicallySmallestStringAfterSubstringOperationTestFixture,
       Example1) {
  EXPECT_EQ("baabc", run("cbabc", solution_));
}

TEST_P(LexicographicallySmallestStringAfterSubstringOperationTestFixture,
       Example2) {
  EXPECT_EQ("az", run("aa", solution_));
}

TEST_P(LexicographicallySmallestStringAfterSubstringOperationTestFixture,
       Example3) {
  EXPECT_EQ("abaab", run("acbbc", solution_));
}

TEST_P(LexicographicallySmallestStringAfterSubstringOperationTestFixture,
       Example4) {
  EXPECT_EQ("kddsbncd", run("leetcode", solution_));
}

TEST_P(LexicographicallySmallestStringAfterSubstringOperationTestFixture,
       SingleCharNonA) {
  EXPECT_EQ("a", run("b", solution_));
}

TEST_P(LexicographicallySmallestStringAfterSubstringOperationTestFixture,
       SingleCharA) {
  EXPECT_EQ("z", run("a", solution_));
}

TEST_P(LexicographicallySmallestStringAfterSubstringOperationTestFixture,
       AllAExceptOne) {
  // "aazaaaaaa": first non-'a' is at index 2 ('z'); the next char is 'a', so
  // only index 2 is decremented: 'z' -> 'y'.
  EXPECT_EQ("aayaaaaaa", run("aazaaaaaa", solution_));
}

TEST_P(LexicographicallySmallestStringAfterSubstringOperationTestFixture,
       LeadingBlockThenA) {
  // "abazy": first non-'a' at index 1 ('b'), decrement up to the 'a' at index 3.
  // 'b'->'a', 'a'(idx2) unchanged? No: stop at first 'a' encountered.
  EXPECT_EQ("aaazy", run("abazy", solution_));
}

INSTANTIATE_TEST_SUITE_P(
    LexicographicallySmallestStringAfterSubstringOperation,
    LexicographicallySmallestStringAfterSubstringOperationTestFixture,
    ::testing::ValuesIn(
        LexicographicallySmallestStringAfterSubstringOperationSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_2734
