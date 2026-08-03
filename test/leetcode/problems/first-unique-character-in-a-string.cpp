#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/first-unique-character-in-a-string.h"

namespace leetcode {
namespace problem_387 {
namespace {

class FirstUniqueCharacterInAStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FirstUniqueCharacterInAStringSolution solution_;
};

TEST_P(FirstUniqueCharacterInAStringTest, Example1) {
  EXPECT_EQ(solution_.firstUniqChar("leetcode"), 0);
}

TEST_P(FirstUniqueCharacterInAStringTest, Example2) {
  EXPECT_EQ(solution_.firstUniqChar("loveleetcode"), 2);
}

TEST_P(FirstUniqueCharacterInAStringTest, Example3) {
  EXPECT_EQ(solution_.firstUniqChar("aabb"), -1);
}

TEST_P(FirstUniqueCharacterInAStringTest, SelfAuthoredSingleCharacter) {
  EXPECT_EQ(solution_.firstUniqChar("z"), 0);
}

TEST_P(FirstUniqueCharacterInAStringTest, SelfAuthoredRepeatedSingle) {
  EXPECT_EQ(solution_.firstUniqChar("aaaa"), -1);
}

TEST_P(FirstUniqueCharacterInAStringTest, SelfAuthoredUniqueAtEnd) {
  EXPECT_EQ(solution_.firstUniqChar("aabbccd"), 6);
}

INSTANTIATE_TEST_SUITE_P(
    FirstUniqueCharacterInAStringTestParameters,
    FirstUniqueCharacterInAStringTest,
    ::testing::ValuesIn(
        FirstUniqueCharacterInAStringSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_387
}  // namespace leetcode
