#include <gtest/gtest.h>

#include "leetcode/problems/student-attendance-record-i.h"

#include <string>

namespace leetcode {
namespace problem_551 {

class StudentAttendanceRecordITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  StudentAttendanceRecordISolution solution_;
};

TEST_P(StudentAttendanceRecordITest, Example1) {
  EXPECT_TRUE(solution_.checkRecord("PPALLP"));
}

TEST_P(StudentAttendanceRecordITest, Example2) {
  EXPECT_FALSE(solution_.checkRecord("PPALLL"));
}

TEST_P(StudentAttendanceRecordITest, SelfAuthoredTwoAbsences) {
  EXPECT_FALSE(solution_.checkRecord("AA"));
}

TEST_P(StudentAttendanceRecordITest, SelfAuthoredThreeConsecutiveLate) {
  EXPECT_FALSE(solution_.checkRecord("PPPLLLPPP"));
}

TEST_P(StudentAttendanceRecordITest, SelfAuthoredBorderlineEligible) {
  EXPECT_TRUE(solution_.checkRecord("PLLAPLL"));
}

INSTANTIATE_TEST_SUITE_P(
    StudentAttendanceRecordIStrategies, StudentAttendanceRecordITest,
    ::testing::ValuesIn(StudentAttendanceRecordISolution().getStrategyNames()));

}  // namespace problem_551
}  // namespace leetcode
