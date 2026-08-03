#include "leetcode/problems/day-of-the-year.h"

namespace leetcode::problem_1154 {

namespace {

int dayOfYearImpl(std::string date) {
  int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 +
             (date[2] - '0') * 10 + (date[3] - '0');
  int month = (date[5] - '0') * 10 + (date[6] - '0');
  int day = (date[8] - '0') * 10 + (date[9] - '0');

  const int month_days[12] = {31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};

  bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  int result = day;
  for (int i = 0; i < month - 1; ++i) {
    result += month_days[i];
  }
  if (leap && month > 2) {
    result += 1;
  }
  return result;
}

}  // namespace

DayOfTheYearSolution::DayOfTheYearSolution() {
  setMetaInfo({.id = 1154,
               .title = "Day of the Year",
               .url = "https://leetcode.com/problems/day-of-the-year/"});
  registerStrategy({.name = "Simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "String"}},
                   dayOfYearImpl);
}

int DayOfTheYearSolution::dayOfYear(std::string date) {
  return getSolution()(date);
}

}  // namespace leetcode::problem_1154
