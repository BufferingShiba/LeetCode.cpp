#include "leetcode/problems/sort-array-by-increasing-frequency.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_1636 {

static vector<int> solution1(vector<int>& nums) {
  std::unordered_map<int, int> freq;
  for (int v : nums) {
    ++freq[v];
  }
  std::sort(nums.begin(), nums.end(), [&](int a, int b) {
    if (freq[a] != freq[b]) {
      return freq[a] < freq[b];
    }
    return a > b;
  });
  return nums;
}

SortArrayByIncreasingFrequencySolution::SortArrayByIncreasingFrequencySolution() {
  setMetaInfo({
      .id = 1636,
      .title = "Sort Array by Increasing Frequency",
      .url = "https://leetcode.com/problems/sort-array-by-increasing-frequency"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

vector<int> SortArrayByIncreasingFrequencySolution::frequencySort(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1636
}  // namespace leetcode
