#include "leetcode/problems/average-salary-excluding-the-minimum-and-maximum-salary.h"

namespace leetcode::problem_1491 {

namespace {

double averageImpl(std::vector<int>& salary) {
  int min_s = salary[0];
  int max_s = salary[0];
  long long sum = 0;
  for (int s : salary) {
    sum += s;
    if (s < min_s) min_s = s;
    if (s > max_s) max_s = s;
  }
  return static_cast<double>(sum - min_s - max_s) / (salary.size() - 2);
}

}  // namespace

AverageSalaryExcludingTheMinimumAndMaximumSalarySolution::
    AverageSalaryExcludingTheMinimumAndMaximumSalarySolution() {
  setMetaInfo({.id = 1491,
               .title = "Average Salary Excluding the Minimum and Maximum Salary",
               .url = "https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/"});
  registerStrategy(
      {.name = "single-pass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      averageImpl);
}

double AverageSalaryExcludingTheMinimumAndMaximumSalarySolution::average(
    std::vector<int>& salary) {
  return getSolution()(salary);
}

}  // namespace leetcode::problem_1491
