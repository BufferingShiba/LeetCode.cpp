#include "leetcode/problems/group-anagrams.h"
#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_49 {

static std::vector<std::vector<std::string>> groupAnagramsImpl(std::vector<std::string>& strs) {
  std::unordered_map<std::string, std::vector<std::string>> groups;
  for (auto& s : strs) {
    std::string key = s;
    std::sort(key.begin(), key.end());
    groups[std::move(key)].push_back(s);
  }
  std::vector<std::vector<std::string>> result;
  result.reserve(groups.size());
  for (auto& pair : groups) {
    result.push_back(std::move(pair.second));
  }
  return result;
}

GroupAnagramsSolution::GroupAnagramsSolution() {
  setMetaInfo({.id = 49, .title = "Group Anagrams", .url = "https://leetcode.com/problems/group-anagrams/"});
  registerStrategy(
      {.name = "Sorting",
       .expected = "Accepted",
       .time_complexity = "O(N * K log K)",
       .space_complexity = "O(N * K)",
       .tags = {"Array", "Hash Table", "String", "Sorting"}},
      groupAnagramsImpl);
  setDefaultStrategy();
}

std::vector<std::vector<std::string>> GroupAnagramsSolution::groupAnagrams(
    std::vector<std::string>& strs) {
  return getSolution()(strs);
}

}  // namespace problem_49
}  // namespace leetcode
