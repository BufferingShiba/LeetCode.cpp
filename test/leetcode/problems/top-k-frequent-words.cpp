#include <gtest/gtest.h>

#include "leetcode/problems/top-k-frequent-words.h"

namespace leetcode {
namespace problem_692 {

class TopKFrequentWordsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TopKFrequentWordsSolution solution_;
};

TEST_P(TopKFrequentWordsTest, Example1) {
  std::vector<std::string> words = {"i", "love", "leetcode", "i", "love", "coding"};
  int k = 2;
  std::vector<std::string> expected = {"i", "love"};
  EXPECT_EQ(solution_.topKFrequent(words, k), expected);
}

TEST_P(TopKFrequentWordsTest, Example2) {
  std::vector<std::string> words = {"the", "day", "is", "sunny", "the", "the", "the",
                                    "sunny", "is", "is"};
  int k = 4;
  std::vector<std::string> expected = {"the", "is", "sunny", "day"};
  EXPECT_EQ(solution_.topKFrequent(words, k), expected);
}

INSTANTIATE_TEST_SUITE_P(Strategies, TopKFrequentWordsTest,
                         ::testing::ValuesIn(TopKFrequentWordsSolution().getStrategyNames()));

}  // namespace problem_692
}  // namespace leetcode
