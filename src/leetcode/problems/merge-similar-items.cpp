#include "leetcode/problems/merge-similar-items.h"

#include <map>
#include <utility>

namespace leetcode {
namespace problem_2363 {
namespace {

std::vector<std::vector<int>> mergeSimilarItemsImpl(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2) {
  std::map<int, int> weights;
  for (const auto& item : items1) {
    weights[item[0]] += item[1];
  }
  for (const auto& item : items2) {
    weights[item[0]] += item[1];
  }
  std::vector<std::vector<int>> ret;
  ret.reserve(weights.size());
  for (const auto& [value, weight] : weights) {
    ret.push_back({value, weight});
  }
  return ret;
}

}  // namespace

MergeSimilarItemsSolution::MergeSimilarItemsSolution() {
  setMetaInfo({.id = 2363, .title = "Merge Similar Items", .url = "https://leetcode.com/problems/merge-similar-items/"});
  registerStrategy(
      {.name = "hashmap-sort", .expected = "Accepted", .time_complexity = "O(n + m + K log K)", .space_complexity = "O(n + m)", .tags = {"Array", "Hash Table", "Sorting", "Ordered Set"}},
      mergeSimilarItemsImpl);
}

std::vector<std::vector<int>> MergeSimilarItemsSolution::mergeSimilarItems(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2) {
  return getSolution()(items1, items2);
}

}  // namespace problem_2363
}  // namespace leetcode
