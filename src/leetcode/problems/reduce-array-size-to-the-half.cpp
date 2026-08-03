#include "leetcode/problems/reduce-array-size-to-the-half.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_1338 {

namespace {

int minSetSizeImpl(std::vector<int>& arr) {
  std::unordered_map<int, int> freq;
  for (int v : arr) {
    ++freq[v];
  }

  std::vector<int> counts;
  counts.reserve(freq.size());
  for (auto& kv : freq) {
    counts.push_back(kv.second);
  }

  std::sort(counts.begin(), counts.end(), std::greater<int>());

  const int target = static_cast<int>(arr.size()) / 2;
  int removed = 0;
  int answer = 0;
  for (int c : counts) {
    removed += c;
    ++answer;
    if (removed >= target) {
      break;
    }
  }
  return answer;
}

}  // namespace

ReduceArraySizeToTheHalfSolution::ReduceArraySizeToTheHalfSolution() {
  setMetaInfo({.id = 1338,
               .title = "Reduce Array Size to The Half",
               .url = "https://leetcode.com/problems/reduce-array-size-to-the-half/"});
  registerStrategy(
      {.name = "sort-greedy",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Greedy", "Sorting"},
       .notes = "Count frequencies, sort descending, greedily pick most frequent values until >= n/2 removed."},
      minSetSizeImpl);
}

int ReduceArraySizeToTheHalfSolution::minSetSize(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_1338
}  // namespace leetcode
