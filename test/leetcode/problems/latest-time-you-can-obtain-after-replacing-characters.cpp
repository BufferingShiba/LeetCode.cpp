#include <gtest/gtest.h>

#include "leetcode/problems/latest-time-you-can-obtain-after-replacing-characters.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3114 {
namespace test {

class LatestTimeYouCanObtainAfterReplacingCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LatestTimeYouCanObtainAfterReplacingCharactersSolution solution;
};

TEST_P(LatestTimeYouCanObtainAfterReplacingCharactersTest, Example1) {
  EXPECT_EQ("11:54", solution.findLatestTime("1?:?4"));
}

TEST_P(LatestTimeYouCanObtainAfterReplacingCharactersTest, Example2) {
  EXPECT_EQ("09:59", solution.findLatestTime("0?:5?"));
}

TEST_P(LatestTimeYouCanObtainAfterReplacingCharactersTest, SelfAuthoredCase1) {
  // 必须保证 HH<=11，开头为 ? 时第二位 <=1 才能取 1，否则取 0。
  EXPECT_EQ("11:59", solution.findLatestTime("??:??"));
}

TEST_P(LatestTimeYouCanObtainAfterReplacingCharactersTest, SelfAuthoredCase2) {
  // 第二位为 ?，首位是 0 -> 第二位最大 9。
  EXPECT_EQ("09:59", solution.findLatestTime("0?:??"));
}

INSTANTIATE_TEST_SUITE_P(
    LatestTimeYouCanObtainAfterReplacingCharactersTestSuite,
    LatestTimeYouCanObtainAfterReplacingCharactersTest,
    ::testing::ValuesIn(
        LatestTimeYouCanObtainAfterReplacingCharactersSolution()
            .getStrategyNames()));

}  // namespace test
}  // namespace problem_3114
}  // namespace leetcode
