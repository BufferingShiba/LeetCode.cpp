#include "leetcode/problems/minimum-index-sum-of-two-lists.h"

#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_599 {
namespace {

std::vector<std::string> findRestaurantImpl(std::vector<std::string>& list1,
                                            std::vector<std::string>& list2) {
  std::unordered_map<std::string, int> pos;
  for (int i = 0; i < static_cast<int>(list1.size()); ++i) {
    pos[list1[i]] = i;
  }

  std::vector<std::string> result;
  int minSum = std::numeric_limits<int>::max();
  for (int j = 0; j < static_cast<int>(list2.size()); ++j) {
    auto it = pos.find(list2[j]);
    if (it == pos.end()) continue;
    int sum = it->second + j;
    if (sum < minSum) {
      minSum = sum;
      result.clear();
      result.push_back(list2[j]);
    } else if (sum == minSum) {
      result.push_back(list2[j]);
    }
  }
  return result;
}

}  // namespace

MinimumIndexSumOfTwoListsSolution::MinimumIndexSumOfTwoListsSolution() {
  setMetaInfo({
      599, "Minimum Index Sum of Two Lists",
      "https://leetcode.com/problems/minimum-index-sum-of-two-lists/"});
  registerStrategy(
      {"HashMapSinglePass", "Accepted", "O(n + m)", "O(n)",
       {"Array", "Hash Table", "String"}},
      findRestaurantImpl);
}

std::vector<std::string> MinimumIndexSumOfTwoListsSolution::findRestaurant(
    std::vector<std::string>& list1, std::vector<std::string>& list2) {
  return getSolution()(list1, list2);
}

}  // namespace problem_599
}  // namespace leetcode
