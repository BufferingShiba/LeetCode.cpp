#include "leetcode/problems/find-the-sum-of-encrypted-integers.h"

namespace leetcode {
namespace problem_3079 {

namespace {

int sumOfEncryptedIntImpl(std::vector<int>& nums) {
  int total = 0;
  for (int x : nums) {
    int maxDigit = 0;
    int tmp = x;
    int base = 1;
    while (tmp > 0) {
      maxDigit = std::max(maxDigit, tmp % 10);
      tmp /= 10;
      base *= 10;
    }
    int encrypted = 0;
    int power = 1;
    while (power < base) {
      encrypted += maxDigit * power;
      power *= 10;
    }
    total += encrypted;
  }
  return total;
}

}  // namespace

FindTheSumOfEncryptedIntegersSolution::FindTheSumOfEncryptedIntegersSolution() {
  setMetaInfo({.id = 3079,
               .title = "Find the Sum of Encrypted Integers",
               .url = "https://leetcode.com/problems/find-the-sum-of-encrypted-integers/"});
  registerStrategy(
      {.name = "Greedy Digit Encryption",
       .expected = "Accepted",
       .time_complexity = "O(n * d)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      sumOfEncryptedIntImpl);
}

int FindTheSumOfEncryptedIntegersSolution::sumOfEncryptedInt(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3079
}  // namespace leetcode
