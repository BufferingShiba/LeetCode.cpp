#include <gtest/gtest.h>

#include "leetcode/problems/sentence-similarity-iii.h"

namespace leetcode {
namespace problem_1813 {
namespace {

class SentenceSimilarityIiiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SentenceSimilarityIiiSolution solution_;
};

TEST_P(SentenceSimilarityIiiTest, Example1) {
  EXPECT_TRUE(solution_.areSentencesSimilar("My name is Haley", "My Haley"));
}

TEST_P(SentenceSimilarityIiiTest, Example2) {
  EXPECT_FALSE(solution_.areSentencesSimilar("of", "A lot of words"));
}

TEST_P(SentenceSimilarityIiiTest, Example3) {
  EXPECT_TRUE(solution_.areSentencesSimilar("Eating right now", "Eating"));
}

TEST_P(SentenceSimilarityIiiTest, SelfAuthoredInsertAtEnd) {
  EXPECT_TRUE(solution_.areSentencesSimilar("Eating", "Eating right now"));
}

TEST_P(SentenceSimilarityIiiTest, SelfAuthoredInsertAtStart) {
  EXPECT_TRUE(solution_.areSentencesSimilar("Eating", "now Eating"));
}

TEST_P(SentenceSimilarityIiiTest, SelfAuthoredNotSimilar) {
  EXPECT_FALSE(solution_.areSentencesSimilar("Frog cool", "Frogs are cool"));
}

TEST_P(SentenceSimilarityIiiTest, SelfAuthoredIdentical) {
  EXPECT_TRUE(solution_.areSentencesSimilar("Hello Jane", "Hello Jane"));
}

INSTANTIATE_TEST_SUITE_P(
    SentenceSimilarityIiiStrategies, SentenceSimilarityIiiTest,
    ::testing::ValuesIn(SentenceSimilarityIiiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1813
}  // namespace leetcode
