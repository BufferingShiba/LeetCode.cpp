#include "leetcode/problems/single-threaded-cpu.h"

#include <algorithm>
#include <queue>
#include <vector>

namespace leetcode::problem_1834 {

namespace {

std::vector<int> getOrderImpl(std::vector<std::vector<int>>& tasks) {
  int n = static_cast<int>(tasks.size());

  // 存储 {enqueueTime, processingTime, index}
  std::vector<std::tuple<int, int, int>> indexed;
  indexed.reserve(n);
  for (int i = 0; i < n; ++i) {
    indexed.emplace_back(tasks[i][0], tasks[i][1], i);
  }

  // 按 enqueueTime 排序
  std::sort(indexed.begin(), indexed.end(),
            [](const auto& a, const auto& b) {
              return std::get<0>(a) < std::get<0>(b);
            });

  std::vector<int> result;
  result.reserve(n);

  // 最小堆：按 processingTime 升序，平局按 index 升序
  auto cmp = [](const std::tuple<int, int, int>& a,
                const std::tuple<int, int, int>& b) {
    int ptA = std::get<1>(a), ptB = std::get<1>(b);
    if (ptA != ptB) return ptA > ptB;
    return std::get<2>(a) > std::get<2>(b);
  };
  std::priority_queue<std::tuple<int, int, int>,
                      std::vector<std::tuple<int, int, int>>,
                      decltype(cmp)>
      pq(cmp);

  int idx = 0;
  long long curTime = 0;

  while (idx < n || !pq.empty()) {
    // 如果堆为空，跳到下一个任务的到达时间
    if (pq.empty() && idx < n) {
      curTime = std::max(curTime, static_cast<long long>(std::get<0>(indexed[idx])));
    }

    // 将所有已到达的任务加入堆
    while (idx < n && std::get<0>(indexed[idx]) <= curTime) {
      pq.push(indexed[idx]);
      ++idx;
    }

    // 取出最优任务执行
    auto top = pq.top();
    pq.pop();
    result.push_back(std::get<2>(top));
    curTime += std::get<1>(top);
  }

  return result;
}

}  // namespace

SingleThreadedCpuSolution::SingleThreadedCpuSolution() {
  setMetaInfo({.id = 1834,
               .title = "Single-Threaded CPU",
               .url = "https://leetcode.com/problems/single-threaded-cpu/"});

  registerStrategy(
      {.name = "Simulation + Min-Heap",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Sorting", "Heap (Priority Queue)"}},
      getOrderImpl);

  setDefaultStrategy();
}

std::vector<int> SingleThreadedCpuSolution::getOrder(
    std::vector<std::vector<int>>& tasks) {
  return getSolution()(tasks);
}

}  // namespace leetcode::problem_1834
