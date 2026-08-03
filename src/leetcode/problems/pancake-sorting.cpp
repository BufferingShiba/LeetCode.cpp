#include "leetcode/problems/pancake-sorting.h"

#include <algorithm>
#include <utility>

namespace leetcode::problem_969 {

namespace {

std::vector<int> pancakeSortImpl(std::vector<int>& arr) {
  std::vector<int> flips;
  const int n = static_cast<int>(arr.size());
  for (int target = n; target >= 1; --target) {
    // Find current index of target value.
    int pos = -1;
    for (int i = 0; i < n; ++i) {
      if (arr[i] == target) {
        pos = i;
        break;
      }
    }
    if (pos + 1 == target) {
      // Already in final position.
      continue;
    }
    if (pos != 0) {
      // Bring target to the front.
      std::reverse(arr.begin(), arr.begin() + pos + 1);
      flips.push_back(pos + 1);
    }
    // Now target is at index 0; flip to its final position.
    std::reverse(arr.begin(), arr.begin() + target);
    flips.push_back(target);
  }
  return flips;
}

}  // namespace

PancakeSortingSolution::PancakeSortingSolution() {
  setMetaInfo({.id = 969,
               .title = "Pancake Sorting",
               .url = "https://leetcode.com/problems/pancake-sorting/"});
  registerStrategy(
      {"greedy", "Accepted", "O(n^2)", "O(1)",
       {"Array", "Two Pointers", "Greedy", "Sorting"}},
      pancakeSortImpl);
}

std::vector<int> PancakeSortingSolution::pancakeSort(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace leetcode::problem_969
