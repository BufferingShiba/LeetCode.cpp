#include "leetcode/problems/divide-a-string-into-groups-of-size-k.h"

namespace leetcode::problem_2138 {

namespace {

std::vector<std::string> divideStringImpl(std::string s, int k, char fill) {
  std::vector<std::string> result;
  for (int i = 0; i < static_cast<int>(s.size()); i += k) {
    std::string group = s.substr(i, k);
    if (static_cast<int>(group.size()) < k) {
      group.append(k - group.size(), fill);
    }
    result.push_back(group);
  }
  return result;
}

}  // namespace

std::vector<std::string> DivideAStringIntoGroupsOfSizeKSolution::divideString(
    std::string s, int k, char fill) {
  return getSolution()(std::move(s), k, fill);
}

DivideAStringIntoGroupsOfSizeKSolution::DivideAStringIntoGroupsOfSizeKSolution() {
  setMetaInfo({.id = 2138,
               .title = "Divide a String Into Groups of Size k",
               .url = "https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/"});

  registerStrategy(
      {.name = "direct-simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Simulation"}},
      divideStringImpl);
}

}  // namespace leetcode::problem_2138
