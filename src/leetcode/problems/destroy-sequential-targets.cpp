#include "leetcode/problems/destroy-sequential-targets.h"

#include <unordered_map>
#include <vector>

namespace leetcode::problem_2453 {

static int destroyTargetsImpl(std::vector<int>& nums, int space) {
  std::unordered_map<int, int> count;
  std::unordered_map<int, int> min_val;

  for (int x : nums) {
    int r = x % space;
    ++count[r];
    auto it = min_val.find(r);
    if (it == min_val.end() || x < it->second) {
      min_val[r] = x;
    }
  }

  int max_count = 0;
  int answer = 0;

  for (auto& [r, cnt] : count) {
    if (cnt > max_count) {
      max_count = cnt;
      answer = min_val[r];
    } else if (cnt == max_count && min_val[r] < answer) {
      answer = min_val[r];
    }
  }

  return answer;
}

DestroySequentialTargetsSolution::DestroySequentialTargetsSolution() {
  setMetaInfo({.id = 2453,
               .title = "Destroy Sequential Targets",
               .url = "https://leetcode.com/problems/destroy-sequential-targets/"});
  registerStrategy(
      {.name = "HashTable",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Counting"}},
      destroyTargetsImpl);
  setDefaultStrategy();
}

int DestroySequentialTargetsSolution::destroyTargets(std::vector<int>& nums, int space) {
  return getSolution()(nums, space);
}

}  // namespace leetcode::problem_2453
