#include "leetcode/problems/task-scheduler.h"

#include <array>
#include <algorithm>

namespace leetcode {
namespace problem_621 {

namespace {

int leastIntervalImpl(std::vector<char>& tasks, int n) {
  const int k = 26;
  std::array<int, k> freq{};
  for (char c : tasks) {
    ++freq[c - 'A'];
  }

  int max_count = 0;
  int max_task_cnt = 0;
  for (int f : freq) {
    if (f > max_count) {
      max_count = f;
      max_task_cnt = 1;
    } else if (f == max_count && f > 0) {
      ++max_task_cnt;
    }
  }

  if (n == 0) {
    return static_cast<int>(tasks.size());
  }

  long long intervals = static_cast<long long>(max_count - 1) * (n + 1) + max_task_cnt;
  return static_cast<int>(std::max(intervals, static_cast<long long>(tasks.size())));
}

}  // namespace

TaskSchedulerSolution::TaskSchedulerSolution() {
  setMetaInfo({.id = 621, .title = "Task Scheduler", .url = "https://leetcode.com/problems/task-scheduler/"});

  registerStrategy(
      {
          .name = "GreedyCounting",
          .expected = "Accepted",
          .time_complexity = "O(26)",
          .space_complexity = "O(26)",
          .tags = {"Array", "Hash Table", "Greedy", "Sorting", "Counting"},
      },
      leastIntervalImpl);
}

int TaskSchedulerSolution::leastInterval(std::vector<char>& tasks, int n) {
  return getSolution()(tasks, n);
}

}  // namespace problem_621
}  // namespace leetcode
