#include <gtest/gtest.h>

#include "leetcode/problems/using-a-robot-to-print-the-lexicographically-smallest-string.h"

namespace leetcode {
namespace problem_2434 {
namespace {

using TestParam = std::string;

class UsingARobotToPrintTheLexicographicallySmallestStringTest
    : public ::testing::TestWithParam<TestParam> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  UsingARobotToPrintTheLexicographicallySmallestStringSolution solution_;
};

TEST_P(UsingARobotToPrintTheLexicographicallySmallestStringTest,
       OfficialExample1) {
  EXPECT_EQ(solution_.robotWithString("zza"), "azz");
}

TEST_P(UsingARobotToPrintTheLexicographicallySmallestStringTest,
       OfficialExample2) {
  EXPECT_EQ(solution_.robotWithString("bac"), "abc");
}

TEST_P(UsingARobotToPrintTheLexicographicallySmallestStringTest,
       OfficialExample3) {
  EXPECT_EQ(solution_.robotWithString("bdda"), "addb");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    UsingARobotToPrintTheLexicographicallySmallestStringTest,
    ::testing::ValuesIn(
        UsingARobotToPrintTheLexicographicallySmallestStringSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_2434
}  // namespace leetcode
