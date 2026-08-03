#include "leetcode/problems/maximize-points-after-choosing-k-tasks.h"

#include <algorithm>
#include <numeric>
#include <vector>

namespace leetcode::problem_3767 {

static long long maxPointsImpl(std::vector<int>& technique1,
                               std::vector<int>& technique2, int k) {
  int n = static_cast<int>(technique1.size());
  if (n == 0) return 0;

  // 按 diff = t1 - t2 降序排列索引
  std::vector<int> idx(n);
  std::iota(idx.begin(), idx.end(), 0);
  std::sort(idx.begin(), idx.end(), [&](int i, int j) {
    return (technique1[i] - technique2[i]) > (technique1[j] - technique2[j]);
  });

  long long ans = 0;

  // 前 k 个强制用 technique1
  for (int p = 0; p < k; ++p) {
    ans += technique1[idx[p]];
  }

  // 剩余任务取两种技术的最大值
  for (int p = k; p < n; ++p) {
    int i = idx[p];
    ans += std::max(technique1[i], technique2[i]);
  }

  return ans;
}

MaximizePointsAfterChoosingKTasksSolution::
    MaximizePointsAfterChoosingKTasksSolution() {
  setMetaInfo({.id = 3767,
               .title = "Maximize Points After Choosing K Tasks",
               .url = "https://leetcode.com/problems/maximize-points-after-choosing-k-tasks/"});

  registerStrategy(
      {.name = "GreedySorting",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Sorting"}},
      maxPointsImpl);

  setDefaultStrategy();
}

long long MaximizePointsAfterChoosingKTasksSolution::maxPoints(
    std::vector<int>& technique1, std::vector<int>& technique2, int k) {
  return getSolution()(technique1, technique2, k);
}

}  // namespace leetcode::problem_3767
