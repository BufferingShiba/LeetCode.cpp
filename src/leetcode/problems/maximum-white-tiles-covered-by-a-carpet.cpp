#include "leetcode/problems/maximum-white-tiles-covered-by-a-carpet.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2271 {

namespace {

int maximumWhiteTilesImpl(std::vector<std::vector<int>>& tiles, int carpetLen) {
  int n = static_cast<int>(tiles.size());
  if (n == 0) return 0;

  std::sort(tiles.begin(), tiles.end());

  std::vector<long long> pref(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + (tiles[i][1] - tiles[i][0] + 1);
  }

  long long ans = 0;

  // 左对齐：地毯左边界对齐 tiles[i][0]
  for (int i = 0; i < n; ++i) {
    long long start = tiles[i][0];
    long long end = start + carpetLen - 1;

    // 二分找最右的 j 使得 tiles[j][0] <= end
    int lo = i, hi = n - 1, j = i;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (tiles[mid][0] <= end) {
        j = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    long long covered = pref[j] - pref[i] +
                        std::min<long long>(tiles[j][1], end) - tiles[j][0] + 1;
    if (covered > ans) ans = covered;
  }

  // 右对齐：地毯右边界对齐 tiles[j][1]
  for (int j_idx = 0; j_idx < n; ++j_idx) {
    long long end = tiles[j_idx][1];
    long long start = end - carpetLen + 1;

    // 二分找最左的 i 使得 tiles[i][1] >= start
    int lo = 0, hi = j_idx, i = j_idx;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (tiles[mid][1] >= start) {
        i = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    // tiles[i..j_idx] 被覆盖
    long long covered =
        pref[j_idx + 1] - pref[i + 1] +  // 完全覆盖的中间瓷砖
        tiles[i][1] - std::max<long long>(tiles[i][0], start) + 1;  // 部分覆盖最左瓷砖
    if (covered > ans) ans = covered;
  }

  return static_cast<int>(ans);
}

}  // namespace

MaximumWhiteTilesCoveredByACarpetSolution::
    MaximumWhiteTilesCoveredByACarpetSolution() {
  setMetaInfo({.id = 2271,
               .title = "Maximum White Tiles Covered by a Carpet",
               .url = "https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/"});
  registerStrategy(
      {.name = "Sorting + Prefix Sum + Binary Search",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Binary Search", "Greedy", "Sliding Window", "Sorting", "Prefix Sum"}},
      maximumWhiteTilesImpl);
}

int MaximumWhiteTilesCoveredByACarpetSolution::maximumWhiteTiles(
    std::vector<std::vector<int>>& tiles, int carpetLen) {
  return getSolution()(tiles, carpetLen);
}

}  // namespace problem_2271
}  // namespace leetcode
