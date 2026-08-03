#include "leetcode/problems/partition-labels.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_763 {

static std::vector<int> partitionLabelsImpl(std::string s) {
  int last[26] = {0};
  int n = static_cast<int>(s.size());
  for (int i = 0; i < n; ++i) {
    last[s[i] - 'a'] = i;
  }

  std::vector<int> result;
  int start = 0;
  int end = 0;
  for (int i = 0; i < n; ++i) {
    end = std::max(end, last[s[i] - 'a']);
    if (i == end) {
      result.push_back(end - start + 1);
      start = i + 1;
    }
  }
  return result;
}

PartitionLabelsSolution::PartitionLabelsSolution() {
  setMetaInfo({.id = 763,
               .title = "Partition Labels",
               .url = "https://leetcode.com/problems/partition-labels/"});
  registerStrategy(
      {.name = "Greedy Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "Two Pointers", "String", "Greedy"}},
      partitionLabelsImpl);
  setDefaultStrategy();
}

std::vector<int> PartitionLabelsSolution::partitionLabels(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_763
}  // namespace leetcode
