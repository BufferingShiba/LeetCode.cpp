#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/minimum-number-of-operations-to-convert-time.h"

namespace leetcode {
namespace problem_2224 {
namespace {

class MinimumNumberOfOperationsToConvertTimeTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumNumberOfOperationsToConvertTimeSolution solution_;
};

TEST_P(MinimumNumberOfOperationsToConvertTimeTest, OfficialExamples) {
  EXPECT_EQ(solution_.convertTime("02:30", "04:35"), 3);
  EXPECT_EQ(solution_.convertTime("11:00", "11:01"), 1);
}

TEST_P(MinimumNumberOfOperationsToConvertTimeTest, SelfAuthored) {
  // Same time, zero operations
  EXPECT_EQ(solution_.convertTime("00:00", "00:00"), 0);

  // Only 60-minute steps
  EXPECT_EQ(solution_.convertTime("00:00", "02:00"), 2);

  // Mixed denominations: 81 min = 60+15+5+1 → 4 ops
  EXPECT_EQ(solution_.convertTime("00:00", "01:21"), 4);

  // 16 min = 15+1 → 2 ops
  EXPECT_EQ(solution_.convertTime("00:00", "00:16"), 2);
}

INSTANTIATE_TEST_SUITE_P(Strategies, MinimumNumberOfOperationsToConvertTimeTest,
                         testing::ValuesIn(
                             MinimumNumberOfOperationsToConvertTimeSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2224
}  // namespace leetcode
