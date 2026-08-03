#include "leetcode/problems/reschedule-meetings-for-maximum-free-time-i.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3439 {

class RescheduleMeetingsForMaximumFreeTimeITest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RescheduleMeetingsForMaximumFreeTimeISolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
// Output: 2
TEST_P(RescheduleMeetingsForMaximumFreeTimeITest, OfficialExample1) {
  vector<int> startTime{1, 3};
  vector<int> endTime{2, 5};
  int result = solution.maxFreeTime(5, 1, startTime, endTime);
  EXPECT_EQ(2, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]
// Output: 6
TEST_P(RescheduleMeetingsForMaximumFreeTimeITest, OfficialExample2) {
  vector<int> startTime{0, 2, 9};
  vector<int> endTime{1, 4, 10};
  int result = solution.maxFreeTime(10, 1, startTime, endTime);
  EXPECT_EQ(6, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
// Output: 0
TEST_P(RescheduleMeetingsForMaximumFreeTimeITest, OfficialExample3) {
  vector<int> startTime{0, 1, 2, 3, 4};
  vector<int> endTime{1, 2, 3, 4, 5};
  int result = solution.maxFreeTime(5, 2, startTime, endTime);
  EXPECT_EQ(0, result);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, RescheduleMeetingsForMaximumFreeTimeITest,
    ::testing::ValuesIn(RescheduleMeetingsForMaximumFreeTimeISolution().getStrategyNames()));

}  // namespace problem_3439
}  // namespace leetcode
