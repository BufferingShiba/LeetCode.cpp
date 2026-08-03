#include "leetcode/problems/number-of-distinct-averages.h"

#include <algorithm>
#include <vector>

#include <unordered_set>

namespace leetcode::problem_2465 {

namespace {

int distinctAveragesImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  std::unordered_set<int> sums;
  int left = 0;
  int right = static_cast<int>(nums.size()) - 1;
  while (left < right) {
    sums.insert(nums[left] + nums[right]);
    ++left;
    --right;
  }
  return static_cast<int>(sums.size());
}

}  // namespace

NumberOfDistinctAveragesSolution::NumberOfDistinctAveragesSolution() {
  setMetaInfo({.id = 2465, .title = "Number of Distinct Averages", .url = "https://leetcode.com/problems/number-of-distinct-averages/"});
  registerStrategy({.name = "sort + two pointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table", "Two Pointers", "Sorting"}},
                   distinctAveragesImpl);
}

int NumberOfDistinctAveragesSolution::distinctAverages(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2465
