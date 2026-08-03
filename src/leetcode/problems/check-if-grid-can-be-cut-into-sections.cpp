#include <algorithm>
#include <utility>
#include <vector>

#include "leetcode/problems/check-if-grid-can-be-cut-into-sections.h"

namespace leetcode {
namespace problem_3394 {

namespace {

// 对一组区间 [start, end]，统计互不重叠的独立块数量。
// 排序后扫描，维护当前合并块的最大右端点；当新的 start >= maxEnd 时开启新块。
int countIndependentBlocks(std::vector<std::pair<long long, long long>> intervals) {
  std::sort(intervals.begin(), intervals.end());
  long long currentMaxEnd = -1;
  int blocks = 0;
  for (const auto& itv : intervals) {
    if (itv.first >= currentMaxEnd) {
      ++blocks;
      currentMaxEnd = itv.second;
    } else {
      currentMaxEnd = std::max(currentMaxEnd, itv.second);
    }
  }
  return blocks;
}

bool canCutImpl(int n,
                std::vector<std::vector<int>>& rectangles) {
  // 垂直切割：检查 x 方向区间（即水平方向投影）
  {
    std::vector<std::pair<long long, long long>> intervals;
    intervals.reserve(rectangles.size());
    for (const auto& r : rectangles) {
      intervals.emplace_back(r[0], r[2]);
    }
    if (countIndependentBlocks(std::move(intervals)) >= 3) return true;
  }
  // 水平切割：检查 y 方向区间（即垂直方向投影）
  {
    std::vector<std::pair<long long, long long>> intervals;
    intervals.reserve(rectangles.size());
    for (const auto& r : rectangles) {
      intervals.emplace_back(r[1], r[3]);
    }
    if (countIndependentBlocks(std::move(intervals)) >= 3) return true;
  }
  return false;
}

}  // namespace

CheckIfGridCanBeCutIntoSectionsSolution::
    CheckIfGridCanBeCutIntoSectionsSolution() {
  setMetaInfo({.id = 3394,
               .title = "Check if Grid can be Cut into Sections",
               .url = "https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/"});
  registerStrategy(
      {.name = "IntervalSweep",
       .expected = "Accepted",
       .time_complexity = "O(R log R)",
       .space_complexity = "O(R)",
       .tags = {"Array", "Sorting"},
       .notes = "缩段至独立区间块计数：任一维度投影块数>=3即可切两刀"},
      canCutImpl);
}

bool CheckIfGridCanBeCutIntoSectionsSolution::checkValidCuts(
    int n, std::vector<std::vector<int>>& rectangles) {
  return getSolution()(n, rectangles);
}

}  // namespace problem_3394
}  // namespace leetcode
