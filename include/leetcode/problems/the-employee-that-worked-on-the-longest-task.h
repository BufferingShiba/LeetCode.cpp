#ifndef LEETCODE_PROBLEMS_THE_EMPLOYEE_THAT_WORKED_ON_THE_LONGEST_TASK_H__
#define LEETCODE_PROBLEMS_THE_EMPLOYEE_THAT_WORKED_ON_THE_LONGEST_TASK_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2432 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class TheEmployeeThatWorkedOnTheLongestTaskSolution
    : public SolutionBase<Func> {
 public:
  TheEmployeeThatWorkedOnTheLongestTaskSolution();

  int hardestWorker(int n, std::vector<std::vector<int>>& logs);
};

}  // namespace leetcode::problem_2432

#endif  // LEETCODE_PROBLEMS_THE_EMPLOYEE_THAT_WORKED_ON_THE_LONGEST_TASK_H__
