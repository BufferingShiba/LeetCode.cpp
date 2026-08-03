#include "leetcode/problems/sum-of-elements-with-frequency-divisible-by-k.h"

#include <unordered_map>

namespace leetcode::problem_3712 {

namespace {

int sumDivisibleByKImpl(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> freq;
  for (int v : nums) {
    ++freq[v];
  }
  int sum = 0;
  for (auto& [v, cnt] : freq) {
    if (cnt % k == 0) {
      sum += v * cnt;
    }
  }
  return sum;
}

}  // namespace

SumOfElementsWithFrequencyDivisibleByKSolution::
    SumOfElementsWithFrequencyDivisibleByKSolution() {
  setMetaInfo({.id = 3712,
               .title = "Sum of Elements With Frequency Divisible by K",
               .url = "https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/"});
  registerStrategy(
      {.name = "hashmap-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Counting"}},
      sumDivisibleByKImpl);
}

int SumOfElementsWithFrequencyDivisibleByKSolution::sumDivisibleByK(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_3712
