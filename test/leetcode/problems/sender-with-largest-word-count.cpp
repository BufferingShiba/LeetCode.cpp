#include "leetcode/problems/sender-with-largest-word-count.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2284 {
namespace {

class SenderWithLargestWordCountTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SenderWithLargestWordCountSolution solution;
};

TEST_P(SenderWithLargestWordCountTest, Example1) {
  std::vector<std::string> messages = {"Hello userTwooo", "Hi userThree",
                                       "Wonderful day Alice", "Nice day userThree"};
  std::vector<std::string> senders = {"Alice", "userTwo", "userThree", "Alice"};
  EXPECT_EQ("Alice", solution.largestWordCount(messages, senders));
}

TEST_P(SenderWithLargestWordCountTest, Example2) {
  std::vector<std::string> messages = {"How is leetcode for everyone",
                                       "Leetcode is useful for practice"};
  std::vector<std::string> senders = {"Bob", "Charlie"};
  EXPECT_EQ("Charlie", solution.largestWordCount(messages, senders));
}

TEST_P(SenderWithLargestWordCountTest, SelfAuthoredTieLexicographicallyLarger) {
  std::vector<std::string> messages = {"a b", "c d", "e f"};
  std::vector<std::string> senders = {"alice", "Bob", "alice"};
  // alice: 2 + 2 = 4, Bob: 2; distinct largest
  EXPECT_EQ("alice", solution.largestWordCount(messages, senders));
}

TEST_P(SenderWithLargestWordCountTest, SelfAuthoredCaseSensitiveDistinct) {
  std::vector<std::string> messages = {"a b", "c d"};
  std::vector<std::string> senders = {"Alice", "alice"};
  // tie of 2 each; "alice" > "Alice" lexicographically (uppercase before lowercase)
  EXPECT_EQ("alice", solution.largestWordCount(messages, senders));
}

TEST_P(SenderWithLargestWordCountTest, SelfAuthoredSingleMessage) {
  std::vector<std::string> messages = {"hello"};
  std::vector<std::string> senders = {"solo"};
  EXPECT_EQ("solo", solution.largestWordCount(messages, senders));
}

INSTANTIATE_TEST_SUITE_P(
    SenderWithLargestWordCountTestSuite, SenderWithLargestWordCountTest,
    ::testing::ValuesIn(SenderWithLargestWordCountSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2284
}  // namespace leetcode
