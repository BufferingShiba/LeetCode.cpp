#include "leetcode/problems/sum-of-digits-of-string-after-convert.h"

namespace leetcode::problem_1945 {
namespace {

int getLuckyImpl(std::string s, int k) {
  long long sum = 0;
  // Convert letters to their alphabet positions and sum digits directly.
  for (char c : s) {
    int pos = c - 'a' + 1;
    sum += pos / 10 + pos % 10;
  }
  // Already performed one transform; repeat k-1 more times.
  while (--k > 0) {
    int ns = 0;
    while (sum > 0) {
      ns += sum % 10;
      sum /= 10;
    }
    sum = ns;
  }
  return static_cast<int>(sum);
}

}  // namespace

SumOfDigitsOfStringAfterConvertSolution::SumOfDigitsOfStringAfterConvertSolution() {
  setMetaInfo({.id = 1945,
               .title = "Sum of Digits of String After Convert",
               .url = "https://leetcode.com/problems/sum-of-digits-of-string-after-convert/"});
  registerStrategy({.name = "DirectSimulation",
                    .expected = "Accepted",
                    .time_complexity = "O(s.length + k * digits)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Simulation"}},
                   &getLuckyImpl);
}

int SumOfDigitsOfStringAfterConvertSolution::getLucky(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

}  // namespace leetcode::problem_1945
