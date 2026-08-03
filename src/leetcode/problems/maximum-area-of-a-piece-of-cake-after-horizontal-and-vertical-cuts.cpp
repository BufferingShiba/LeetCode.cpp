#include "leetcode/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts.h"

#include <algorithm>
#include <cstdint>

namespace leetcode::problem_1465 {

namespace {

constexpr int64_t kMod = 1000000007;

// 求 [0, limit] 上按 cuts 切割后的最大相邻间隙。
int64_t maxGap(int limit, std::vector<int>& cuts) {
  std::sort(cuts.begin(), cuts.end());
  int64_t best = 0;
  int prev = 0;
  for (int c : cuts) {
    best = std::max(best, static_cast<int64_t>(c - prev));
    prev = c;
  }
  best = std::max(best, static_cast<int64_t>(limit - prev));
  return best;
}

int maxAreaImpl(int h, int w, std::vector<int>& horizontalCuts,
                std::vector<int>& verticalCuts) {
  int64_t maxH = maxGap(h, horizontalCuts);
  int64_t maxV = maxGap(w, verticalCuts);
  return static_cast<int>((maxH % kMod) * (maxV % kMod) % kMod);
}

}  // namespace

MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsSolution::
    MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsSolution() {
  setMetaInfo({.id = 1465,
               .title = "Maximum Area of a Piece of Cake After Horizontal and "
                        "Vertical Cuts",
               .url = "https://leetcode.com/problems/"
                      "maximum-area-of-a-piece-of-cake-after-horizontal-and-"
                      "vertical-cuts/"});
  registerStrategy({.name =
                        "SortedGapMultiplication",
                    .expected = "Accepted",
                    .time_complexity = "O(hl·log(hl) + vl·log(vl))",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy", "Sorting"}},
                   maxAreaImpl);
}

int MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsSolution::maxArea(
    int h, int w, std::vector<int>& horizontalCuts,
    std::vector<int>& verticalCuts) {
  return getSolution()(h, w, horizontalCuts, verticalCuts);
}

}  // namespace leetcode::problem_1465
