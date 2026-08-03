#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/sorting-the-sentence.h"

namespace leetcode {
namespace problem_1859 {

class SortingTheSentenceTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortingTheSentenceSolution solution;
};

TEST_P(SortingTheSentenceTest, OfficialExamples) {
  EXPECT_EQ(solution.sortSentence("is2 sentence4 This1 a3"),
            "This is a sentence");
  EXPECT_EQ(solution.sortSentence("Myself2 Me1 I4 and3"),
            "Me Myself and I");
}

TEST_P(SortingTheSentenceTest, SelfAuthored) {
  // Single word
  EXPECT_EQ(solution.sortSentence("hello1"), "hello");
  // Already sorted
  EXPECT_EQ(solution.sortSentence("a1 b2 c3"), "a b c");
  // Reverse order
  EXPECT_EQ(solution.sortSentence("c3 b2 a1"), "a b c");
}

INSTANTIATE_TEST_SUITE_P(Strategies, SortingTheSentenceTest,
                         ::testing::ValuesIn(
                             SortingTheSentenceSolution().getStrategyNames()));

}  // namespace problem_1859
}  // namespace leetcode
