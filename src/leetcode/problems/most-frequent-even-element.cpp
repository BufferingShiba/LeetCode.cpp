#include "leetcode/problems/most-frequent-even-element.h"

namespace leetcode {
namespace problem_2404 {

namespace {

int mostFrequentEvenImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> count;
  int bestValue = -1;
  int bestFreq = 0;
  for (int x : nums) {
    if (x % 2 != 0) continue;
    int freq = ++count[x];
    if (freq > bestFreq || (freq == bestFreq && x < bestValue)) {
      bestFreq = freq;
      bestValue = x;
    }
  }
  return bestValue;
}

}  // namespace

MostFrequentEvenElementSolution::MostFrequentEvenElementSolution() {
  setMetaInfo({2404, "Most Frequent Even Element",
               "https://leetcode.com/problems/most-frequent-even-element/"});
  registerStrategy(
      {"HashTableCounting", "Accepted", "O(n)", "O(n)",
       {"Array", "Hash Table", "Counting"}},
      mostFrequentEvenImpl);
}

int MostFrequentEvenElementSolution::mostFrequentEven(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2404
}  // namespace leetcode
