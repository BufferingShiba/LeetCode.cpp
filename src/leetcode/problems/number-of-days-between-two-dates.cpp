#include "leetcode/problems/number-of-days-between-two-dates.h"

#include <cstdlib>
#include <string>

namespace leetcode {
namespace problem_1360 {

namespace {

bool isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysFromEpoch(int year, int month, int day) {
  static const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};
  int total = 0;
  for (int y = 1971; y < year; ++y) {
    total += isLeapYear(y) ? 366 : 365;
  }
  for (int m = 1; m < month; ++m) {
    total += monthDays[m - 1];
    if (m == 2 && isLeapYear(year)) {
      total += 1;
    }
  }
  total += day;
  return total;
}

int daysBetweenDatesImpl(const std::string& date1,
                         const std::string& date2) {
  int y1 = std::stoi(date1.substr(0, 4));
  int m1 = std::stoi(date1.substr(5, 2));
  int d1 = std::stoi(date1.substr(8, 2));

  int y2 = std::stoi(date2.substr(0, 4));
  int m2 = std::stoi(date2.substr(5, 2));
  int d2 = std::stoi(date2.substr(8, 2));

  int days1 = daysFromEpoch(y1, m1, d1);
  int days2 = daysFromEpoch(y2, m2, d2);

  return std::abs(days1 - days2);
}

}  // namespace

NumberOfDaysBetweenTwoDatesSolution::NumberOfDaysBetweenTwoDatesSolution() {
  setMetaInfo({1360, "Number of Days Between Two Dates",
               "https://leetcode.com/problems/number-of-days-between-two-dates/"});
  registerStrategy({.name = "EpochConversion",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "String"}},
                   daysBetweenDatesImpl);
}

int NumberOfDaysBetweenTwoDatesSolution::daysBetweenDates(
    std::string date1, std::string date2) {
  return getSolution()(date1, date2);
}

}  // namespace problem_1360
}  // namespace leetcode
