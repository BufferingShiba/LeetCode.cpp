#include "leetcode/problems/number-of-employees-who-met-the-target.h"

namespace leetcode::problem_2798 {

namespace {

int numberOfEmployeesWhoMetTargetImpl(std::vector<int>& hours, int target) {
  int count = 0;
  for (int h : hours) {
    if (h >= target) {
      ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfEmployeesWhoMetTheTargetSolution::NumberOfEmployeesWhoMetTheTargetSolution() {
  this->setMetaInfo({2798, "Number of Employees Who Met the Target",
                     "https://leetcode.com/problems/number-of-employees-who-met-the-target/"});
  this->registerStrategy({"LinearScan", "Accepted", "O(n)", "O(1)", {"Array"}},
                         numberOfEmployeesWhoMetTargetImpl);
}

int NumberOfEmployeesWhoMetTheTargetSolution::numberOfEmployeesWhoMetTarget(
    std::vector<int>& hours, int target) {
  return getSolution()(hours, target);
}

}  // namespace leetcode::problem_2798
