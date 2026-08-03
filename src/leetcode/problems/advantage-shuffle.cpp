#include "leetcode/problems/advantage-shuffle.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode::problem_870 {

namespace {

std::vector<int> advantageCountImpl(std::vector<int>& nums1, std::vector<int>& nums2) {
  const int n = static_cast<int>(nums1.size());

  std::vector<int> sorted1(nums1.begin(), nums1.end());
  std::sort(sorted1.begin(), sorted1.end());

  // Pair each nums2 value with its original index, sorted ascending by value.
  std::vector<std::pair<int, int>> idx2;
  idx2.reserve(n);
  for (int i = 0; i < n; ++i) {
    idx2.emplace_back(nums2[i], i);
  }
  std::sort(idx2.begin(), idx2.end());

  std::vector<int> result(n, 0);
  int low = 0;
  int high = n - 1;

  // Greedy (Tian Ji's horse racing): process nums2 from the largest down.
  // For the current strongest opponent, if our largest nums1 can beat it, use
  // that; otherwise sacrifice our smallest nums1 against it.
  for (int i = n - 1; i >= 0; --i) {
    if (sorted1[high] > idx2[i].first) {
      result[idx2[i].second] = sorted1[high];
      --high;
    } else {
      result[idx2[i].second] = sorted1[low];
      ++low;
    }
  }

  return result;
}

}  // namespace

AdvantageShuffleSolution::AdvantageShuffleSolution() {
  setMetaInfo({.id = 870,
               .title = "Advantage Shuffle",
               .url = "https://leetcode.com/problems/advantage-shuffle/"});

  registerStrategy(
      {.name = "greedy-two-pointers",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Two Pointers", "Greedy", "Sorting"}},
      advantageCountImpl);
}

std::vector<int> AdvantageShuffleSolution::advantageCount(std::vector<int>& nums1,
                                                           std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace leetcode::problem_870
