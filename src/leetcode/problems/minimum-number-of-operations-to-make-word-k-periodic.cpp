#include "leetcode/problems/minimum-number-of-operations-to-make-word-k-periodic.h"

#include <algorithm>
#include <string>
#include <unordered_map>

namespace leetcode {
namespace problem_3137 {

namespace {

int minimumOperationsToMakeKPeriodicImpl(const std::string& word, int k) {
  std::unordered_map<std::string, int> freq;
  for (int i = 0; i < static_cast<int>(word.size()); i += k) {
    ++freq[word.substr(i, k)];
  }
  int maxFreq = 0;
  for (const auto& entry : freq) {
    maxFreq = std::max(maxFreq, entry.second);
  }
  return static_cast<int>(word.size() / k) - maxFreq;
}

}  // namespace

MinimumNumberOfOperationsToMakeWordKPeriodicSolution::
    MinimumNumberOfOperationsToMakeWordKPeriodicSolution() {
  setMetaInfo({.id = 3137,
               .title = "Minimum Number of Operations to Make Word K-Periodic",
               .url = "https://leetcode.com/problems/minimum-number-of-"
                      "operations-to-make-word-k-periodic/"});
  registerStrategy(
      {.name = "hashmap-counting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String", "Counting"}},
      minimumOperationsToMakeKPeriodicImpl);
}

int MinimumNumberOfOperationsToMakeWordKPeriodicSolution::
    minimumOperationsToMakeKPeriodic(std::string word, int k) {
  return getSolution()(std::move(word), k);
}

}  // namespace problem_3137
}  // namespace leetcode
