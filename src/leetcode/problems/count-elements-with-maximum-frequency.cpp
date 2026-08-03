#include "leetcode/problems/count-elements-with-maximum-frequency.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode::problem_3005 {

namespace {

int maxFrequencyElementsImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> freq;
  int max_freq = 0;
  for (int v : nums) {
    freq[v]++;
    max_freq = std::max(max_freq, freq[v]);
  }
  int total = 0;
  for (const auto& [v, f] : freq) {
    if (f == max_freq) {
      total += f;
    }
  }
  return total;
}

}  // namespace

CountElementsWithMaximumFrequencySolution::CountElementsWithMaximumFrequencySolution() {
  setMetaInfo({.id = 3005,
               .title = "Count Elements With Maximum Frequency",
               .url = "https://leetcode.com/problems/count-elements-with-maximum-frequency/"});
  registerStrategy(
      {.name = "hashmap-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Counting"}},
      maxFrequencyElementsImpl);
}

int CountElementsWithMaximumFrequencySolution::maxFrequencyElements(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3005
