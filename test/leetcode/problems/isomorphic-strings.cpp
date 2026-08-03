#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/isomorphic-strings.h"

namespace leetcode {
namespace problem_205 {
namespace {

class IsomorphicStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  IsomorphicStringsSolution solution_;
};

TEST_P(IsomorphicStringsTest, Example1) {
  EXPECT_TRUE(solution_.isIsomorphic("egg", "add"));
}

TEST_P(IsomorphicStringsTest, Example2) {
  EXPECT_FALSE(solution_.isIsomorphic("foo", "bar"));
}

TEST_P(IsomorphicStringsTest, Example3) {
  EXPECT_TRUE(solution_.isIsomorphic("paper", "title"));
}

TEST_P(IsomorphicStringsTest, SelfAuthoredReversedMapping) {
  // 'a'->'b', 'b'->'a' 允许，因为不冲突
  EXPECT_TRUE(solution_.isIsomorphic("ab", "ba"));
}

TEST_P(IsomorphicStringsTest, SelfAuthoredSameCharMapsToTwoTargets) {
  // 同一字符 'a' 映射到 'b' 和 'c'，不合法
  EXPECT_FALSE(solution_.isIsomorphic("aa", "bc"));
}

TEST_P(IsomorphicStringsTest, SelfAuthoredSingleChar) {
  EXPECT_TRUE(solution_.isIsomorphic("a", "z"));
}

INSTANTIATE_TEST_SUITE_P(
    IsomorphicStringsTestSuite, IsomorphicStringsTest,
    ::testing::ValuesIn(IsomorphicStringsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_205
}  // namespace leetcode
