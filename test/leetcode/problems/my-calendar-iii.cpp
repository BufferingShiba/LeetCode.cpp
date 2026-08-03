#include "leetcode/problems/my-calendar-iii.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_732 {
namespace {

class MyCalendarThreeTest : public ::testing::TestWithParam<int> {};

TEST_P(MyCalendarThreeTest, Example1) {
  MyCalendarThree calendar;
  EXPECT_EQ(1, calendar.book(10, 20));
  EXPECT_EQ(1, calendar.book(50, 60));
  EXPECT_EQ(2, calendar.book(10, 40));
  EXPECT_EQ(3, calendar.book(5, 15));
  EXPECT_EQ(3, calendar.book(5, 10));
  EXPECT_EQ(3, calendar.book(25, 55));
}

TEST_P(MyCalendarThreeTest, SelfAuthoredSingleEvent) {
  MyCalendarThree calendar;
  EXPECT_EQ(1, calendar.book(0, 1));
}

TEST_P(MyCalendarThreeTest, SelfAuthoredThreeFoldOverlap) {
  MyCalendarThree calendar;
  EXPECT_EQ(1, calendar.book(1, 5));
  EXPECT_EQ(2, calendar.book(2, 6));
  EXPECT_EQ(3, calendar.book(3, 7));
  // [0,10] covers all three interior events, giving a 4-fold overlap at 3..5.
  EXPECT_EQ(4, calendar.book(0, 10));
}

TEST_P(MyCalendarThreeTest, SelfAuthoredNonOverlapping) {
  MyCalendarThree calendar;
  EXPECT_EQ(1, calendar.book(0, 5));
  EXPECT_EQ(1, calendar.book(5, 10));
  EXPECT_EQ(1, calendar.book(10, 15));
}

INSTANTIATE_TEST_SUITE_P(MyCalendarThreeTestSuite, MyCalendarThreeTest,
                         ::testing::Values(0));

}  // namespace
}  // namespace problem_732
}  // namespace leetcode
