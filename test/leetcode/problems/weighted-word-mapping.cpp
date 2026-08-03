#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/weighted-word-mapping.h"

namespace leetcode {
namespace problem_3838 {
namespace {

class WeightedWordMappingTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  WeightedWordMappingSolution solution_;
};

TEST_P(WeightedWordMappingTest, Example1) {
  std::vector<std::string> words = {"abcd", "def", "xyz"};
  std::vector<int> weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8,
                              7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
  EXPECT_EQ("rij", solution_.mapWordWeights(words, weights));
}

TEST_P(WeightedWordMappingTest, Example2) {
  std::vector<std::string> words = {"a", "b", "c"};
  std::vector<int> weights(26, 1);
  EXPECT_EQ("yyy", solution_.mapWordWeights(words, weights));
}

TEST_P(WeightedWordMappingTest, Example3) {
  std::vector<std::string> words = {"abcd"};
  std::vector<int> weights = {7, 5, 3, 4, 3, 5, 4, 9, 4, 2, 2, 7, 10, 2,
                              5, 10, 6, 1, 2, 2, 4, 1, 3, 4, 4, 5};
  EXPECT_EQ("g", solution_.mapWordWeights(words, weights));
}

TEST_P(WeightedWordMappingTest, SelfAuthoredSingleLetterWeightBoundary) {
  // Single word "a" with weight sum % 26 = 0 maps to 'z'.
  std::vector<std::string> words = {"a"};
  std::vector<int> weights(26, 1);
  weights[0] = 26;
  EXPECT_EQ("z", solution_.mapWordWeights(words, weights));
}

INSTANTIATE_TEST_SUITE_P(WeightedWordMappingTestSuite, WeightedWordMappingTest,
                         ::testing::ValuesIn(WeightedWordMappingSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3838
}  // namespace leetcode
