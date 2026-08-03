#include "leetcode/problems/finding-3-digit-even-numbers.h"

namespace leetcode::problem_2094 {

namespace {

std::vector<int> findEvenNumbersImpl(std::vector<int>& digits) {
  // Frequency of each digit (0..9) in digits.
  std::vector<int> freq(10, 0);
  for (int d : digits) {
    ++freq[d];
  }

  std::vector<int> result;
  // Enumerate all 3-digit even numbers in ascending order. 100 is valid;
  // starting at 102 would incorrectly omit it when two zeroes are present.
  for (int n = 100; n <= 998; n += 2) {
    int a = n / 100;
    int b = (n / 10) % 10;
    int c = n % 10;

    std::vector<int> need(10, 0);
    ++need[a];
    ++need[b];
    ++need[c];

    bool ok = true;
    for (int d = 0; d < 10; ++d) {
      if (need[d] > freq[d]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      result.push_back(n);
    }
  }
  return result;
}

}  // namespace

Finding3DigitEvenNumbersSolution::Finding3DigitEvenNumbersSolution() {
  setMetaInfo({.id = 2094,
               .title = "Finding 3-Digit Even Numbers",
               .url = "https://leetcode.com/problems/finding-3-digit-even-numbers/"});
  registerStrategy(
      {"Enumerate 3-digit even numbers", "Accepted", "O(900) ~ O(1)", "O(1)",
       {"Enumeration", "Hash Table", "Sorting"}},
      findEvenNumbersImpl);
}

std::vector<int> Finding3DigitEvenNumbersSolution::findEvenNumbers(
    std::vector<int>& digits) {
  return getSolution()(digits);
}

}  // namespace leetcode::problem_2094
