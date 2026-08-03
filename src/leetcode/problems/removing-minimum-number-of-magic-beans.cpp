#include "leetcode/problems/removing-minimum-number-of-magic-beans.h"

#include <algorithm>
#include <cstdint>

namespace leetcode::problem_2171 {

namespace {

long long minimumRemovalSortPrefix(std::vector<int>& beans) {
  std::sort(beans.begin(), beans.end());
  const int n = static_cast<int>(beans.size());
  long long total = 0;
  for (int v : beans) total += v;

  long long prefix = 0;
  long long best = total;  // 全部清空的情况已经是一个可行上界

  for (int i = 0; i < n; ++i) {
    // 令 x = beans[i]。左侧（< beans[i]）全部移除，右侧（>= beans[i]）保留 beans[i]。
    const long long x = beans[i];
    // 从左到右: 前 i 个（< x，因为已去重排序）全部移除：prefix
    // 右侧剩余：(total - prefix - x) 个豆子中，每个袋子保留 x，所以每个袋子移除 beans - x。
    // 但这里由于可能有重复值，直接用公式更稳，改为枚举每个元素作为分界处理。
    const long long right_kept = x * (n - i);
    const long long removed = total - right_kept;
    if (removed < best) best = removed;
    prefix += x;
  }
  return best;
}

}  // namespace

RemovingMinimumNumberOfMagicBeansSolution::RemovingMinimumNumberOfMagicBeansSolution() {
  setMetaInfo({
      .id = 2171,
      .title = "Removing Minimum Number of Magic Beans",
      .url = "https://leetcode.com/problems/removing-minimum-number-of-magic-beans/",
  });

  registerStrategy(
      {
          .name = "SortPrefixEnum",
          .expected = "Accepted",
          .time_complexity = "O(n log n)",
          .space_complexity = "O(1)",
          .tags = {"Array", "Greedy", "Sorting", "Enumeration", "Prefix Sum"},
      },
      minimumRemovalSortPrefix);
}

}  // namespace leetcode::problem_2171
