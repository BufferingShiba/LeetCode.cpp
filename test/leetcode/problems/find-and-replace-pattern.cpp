#include <gtest/gtest.h>

#include <algorithm>

#include "leetcode/problems/find-and-replace-pattern.h"

namespace leetcode {
namespace problem_890 {

class FindAndReplacePatternTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  FindAndReplacePatternSolution solution_;
};

TEST_P(FindAndReplacePatternTest, Example1) {
  std::vector<std::string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
  std::string pattern = "abb";
  std::vector<std::string> expected = {"mee", "aqq"};
  auto result = solution_.findAndReplacePattern(words, pattern);
  std::sort(result.begin(), result.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST_P(FindAndReplacePatternTest, Example2) {
  std::vector<std::string> words = {"a", "b", "c"};
  std::string pattern = "a";
  std::vector<std::string> expected = {"a", "b", "c"};
  auto result = solution_.findAndReplacePattern(words, pattern);
  std::sort(result.begin(), result.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Strategies, FindAndReplacePatternTest,
                         ::testing::ValuesIn(FindAndReplacePatternSolution()
                                                 .getStrategyNames()));

}  // namespace problem_890
}  // namespace leetcode
