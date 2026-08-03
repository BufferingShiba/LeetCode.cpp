#include "leetcode/problems/day-of-the-week.h"

namespace leetcode::problem_1185 {
namespace {

// Number of days elapsed from 1971-01-01 to the given date.
int daysSinceReference(int day, int month, int year) {
  static constexpr int kDaysInMonth[] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};

  auto isLeap = [](int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
  };

  int days = 0;
  for (int y = 1971; y < year; ++y) {
    days += isLeap(y) ? 366 : 365;
  }
  for (int m = 1; m < month; ++m) {
    days += kDaysInMonth[m - 1];
    if (m == 2 && isLeap(year)) {
      days += 1;
    }
  }
  days += day - 1;
  return days;
}

std::string dayOfTheWeekImpl(int day, int month, int year) {
  static const char* kWeek[] = {"Sunday",    "Monday", "Tuesday", "Wednesday",
                                "Thursday",  "Friday", "Saturday"};
  // 1971-01-01 was a Friday (index 5).
  return kWeek[(5 + daysSinceReference(day, month, year)) % 7];
}

}  // namespace

DayOfTheWeekSolution::DayOfTheWeekSolution() {
  setMetaInfo({.id = 1185,
               .title = "Day of the Week",
               .url = "https://leetcode.com/problems/day-of-the-week/"});
  registerStrategy({.name = "DateArithmetic",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math"}},
                   dayOfTheWeekImpl);
}

std::string DayOfTheWeekSolution::dayOfTheWeek(int day, int month, int year) {
  return getSolution()(day, month, year);
}

}  // namespace leetcode::problem_1185
