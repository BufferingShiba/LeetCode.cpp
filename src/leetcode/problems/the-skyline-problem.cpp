#include "leetcode/problems/the-skyline-problem.h"

#include <algorithm>
#include <set>
#include <utility>

namespace leetcode {
namespace problem_218 {

namespace {

// Sweep line with a multiset (ordered set) of active heights.
// Events: entering a building at (left, -height), leaving at (right, +height).
// Sort by x ascending; at the same x, process "enter" (negative) before
// "leave" (positive), taller entering buildings first, and shorter leaving
// buildings first, so we never emit transient intermediate heights.
std::vector<std::vector<int>> getSkylineImpl(std::vector<std::vector<int>>& buildings) {
  std::vector<std::pair<int, int>> events;
  events.reserve(buildings.size() * 2);
  for (const auto& b : buildings) {
    events.emplace_back(b[0], -b[2]);
    events.emplace_back(b[1], b[2]);
  }

  std::sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
  });

  std::multiset<int> heights;
  int prev = 0;
  std::vector<std::vector<int>> result;

  for (const auto& e : events) {
    if (e.second < 0) {
      heights.insert(-e.second);
    } else {
      auto it = heights.find(e.second);
      if (it != heights.end()) heights.erase(it);
    }
    int cur = heights.empty() ? 0 : *heights.rbegin();
    if (cur != prev) {
      result.push_back({e.first, cur});
      prev = cur;
    }
  }

  return result;
}

}  // namespace

TheSkylineProblemSolution::TheSkylineProblemSolution() {
  setMetaInfo({.id = 218,
               .title = "The Skyline Problem",
               .url = "https://leetcode.com/problems/the-skyline-problem/"});
  registerStrategy(
      {
          .name = "SweepLineWithMultiset",
          .expected = "Accepted",
          .time_complexity = "O(n log n)",
          .space_complexity = "O(n)",
          .tags = {"Sweep Line", "Sorting", "Heap", "Ordered Set"},
      },
      getSkylineImpl);
}

std::vector<std::vector<int>> TheSkylineProblemSolution::getSkyline(
    std::vector<std::vector<int>>& buildings) {
  return getSolution()(buildings);
}

}  // namespace problem_218
}  // namespace leetcode
