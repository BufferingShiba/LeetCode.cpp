#include "leetcode/problems/check-if-any-element-has-prime-frequency.h"

#include <unordered_map>

namespace leetcode::problem_3591 {

namespace {

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

bool checkPrimeFrequencyImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> freq;
  for (int x : nums) {
    ++freq[x];
  }
  for (const auto& kv : freq) {
    if (isPrime(kv.second)) {
      return true;
    }
  }
  return false;
}

}  // namespace

CheckIfAnyElementHasPrimeFrequencySolution::
    CheckIfAnyElementHasPrimeFrequencySolution() {
  setMetaInfo({.id = 3591,
               .title = "Check if Any Element Has Prime Frequency",
               .url = "https://leetcode.com/problems/check-if-any-element-has-prime-frequency/"});

  registerStrategy(
      {.name = "frequency count + primality test",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Math", "Counting", "Number Theory"}},
      checkPrimeFrequencyImpl);
}

bool CheckIfAnyElementHasPrimeFrequencySolution::checkPrimeFrequency(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3591
