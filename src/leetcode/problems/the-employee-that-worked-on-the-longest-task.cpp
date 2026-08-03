#include "leetcode/problems/the-employee-that-worked-on-the-longest-task.h"

namespace leetcode::problem_2432 {

namespace {

int hardestWorkerImpl(int n, std::vector<std::vector<int>>& logs) {
  int prev = 0;
  int bestId = -1;
  int bestTime = -1;
  for (const auto& log : logs) {
    int id = log[0];
    int duration = log[1] - prev;
    prev = log[1];
    if (duration > bestTime ||
        (duration == bestTime && id < bestId)) {
      bestTime = duration;
      bestId = id;
    }
  }
  return bestId;
}

}  // namespace

TheEmployeeThatWorkedOnTheLongestTaskSolution::
    TheEmployeeThatWorkedOnTheLongestTaskSolution() {
  setMetaInfo({2432, "The Employee That Worked on the Longest Task",
               "https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/"});
  registerStrategy({"SinglePass", "Accepted", "O(n)", "O(1)", {"Array"}},
                    hardestWorkerImpl);
}

int TheEmployeeThatWorkedOnTheLongestTaskSolution::hardestWorker(
    int n, std::vector<std::vector<int>>& logs) {
  return getSolution()(n, logs);
}

}  // namespace leetcode::problem_2432
