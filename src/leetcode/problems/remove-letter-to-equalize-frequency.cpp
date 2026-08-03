#include "leetcode/problems/remove-letter-to-equalize-frequency.h"

#include <array>
#include <functional>
#include <string>

namespace leetcode {
namespace problem_2423 {
namespace {

bool allEqualExcludingZero(const std::array<int, 26>& freq) {
  int target = -1;
  for (int count : freq) {
    if (count == 0) continue;
    if (target == -1) {
      target = count;
    } else if (count != target) {
      return false;
    }
  }
  return true;
}

// Strategy: simulate removing one letter from each distinct letter.
bool equalFrequencyImpl(const std::string& word) {
  std::array<int, 26> freq{};
  for (char c : word) {
    ++freq[c - 'a'];
  }

  for (int i = 0; i < 26; ++i) {
    if (freq[i] == 0) continue;
    --freq[i];
    if (allEqualExcludingZero(freq)) {
      return true;
    }
    ++freq[i];
  }
  return false;
}

}  // namespace

RemoveLetterToEqualizeFrequencySolution::RemoveLetterToEqualizeFrequencySolution() {
  setMetaInfo({.id = 2423,
               .title = "Remove Letter To Equalize Frequency",
               .url = "https://leetcode.com/problems/remove-letter-to-equalize-frequency/"});
  registerStrategy(
      {.name = "simulate-removal",
       .expected = "Accepted",
       .time_complexity = "O(26 * 26) = O(1)",
       .space_complexity = "O(26) = O(1)",
       .tags = {"Hash Table", "String", "Counting"}},
      std::function<bool(std::string)>(equalFrequencyImpl));
}

bool RemoveLetterToEqualizeFrequencySolution::equalFrequency(std::string word) {
  return getSolution()(word);
}

}  // namespace problem_2423
}  // namespace leetcode
