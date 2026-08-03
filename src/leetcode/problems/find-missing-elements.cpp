#include "leetcode/problems/find-missing-elements.h"

#include <algorithm>
#include <unordered_set>

namespace leetcode {
namespace problem_3731 {

namespace {

std::vector<int> findMissingElementsImpl(std::vector<int>& nums) {
  int mn = *std::min_element(nums.begin(), nums.end());
  int mx = *std::max_element(nums.begin(), nums.end());
  std::unordered_set<int> present(nums.begin(), nums.end());

  std::vector<int> result;
  for (int v = mn; v <= mx; ++v) {
    if (present.find(v) == present.end()) {
      result.push_back(v);
    }
  }
  return result;
}

}  // namespace

FindMissingElementsSolution::FindMissingElementsSolution() {
  setMetaInfo({3731, "Find Missing Elements",
               "https://leetcode.com/problems/find-missing-elements/"});
  registerStrategy(
      {"HashSetScan", "Accepted", "O(n + range)", "O(n)",
       {"Array", "Hash Table", "Sorting"}},
      findMissingElementsImpl);
}

std::vector<int> FindMissingElementsSolution::findMissingElements(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3731
}  // namespace leetcode
