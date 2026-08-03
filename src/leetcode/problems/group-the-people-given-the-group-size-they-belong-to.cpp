#include "leetcode/problems/group-the-people-given-the-group-size-they-belong-to.h"

#include <unordered_map>

namespace leetcode {
namespace problem_1282 {

namespace {

std::vector<std::vector<int>> groupThePeopleImpl(std::vector<int>& groupSizes) {
  std::unordered_map<int, std::vector<int>> buckets;
  int n = static_cast<int>(groupSizes.size());
  for (int i = 0; i < n; ++i) {
    buckets[groupSizes[i]].push_back(i);
  }

  std::vector<std::vector<int>> result;
  for (auto& [size, indices] : buckets) {
    std::vector<int> group;
    group.reserve(size);
    for (int idx : indices) {
      group.push_back(idx);
      if (static_cast<int>(group.size()) == size) {
        result.push_back(std::move(group));
        group.clear();
        group.reserve(size);
      }
    }
  }
  return result;
}

}  // namespace

GroupThePeopleGivenTheGroupSizeTheyBelongToSolution::
    GroupThePeopleGivenTheGroupSizeTheyBelongToSolution() {
  setMetaInfo({.id = 1282,
               .title = "Group the People Given the Group Size They Belong To",
               .url = "https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/"});
  registerStrategy(
      {.name = "HashTableGreedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Greedy"}},
      groupThePeopleImpl);
}

std::vector<std::vector<int>>
GroupThePeopleGivenTheGroupSizeTheyBelongToSolution::groupThePeople(
    std::vector<int>& groupSizes) {
  return getSolution()(groupSizes);
}

}  // namespace problem_1282
}  // namespace leetcode
