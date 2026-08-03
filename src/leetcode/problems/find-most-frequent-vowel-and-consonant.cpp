#include "leetcode/problems/find-most-frequent-vowel-and-consonant.h"

#include <string>

namespace leetcode {
namespace problem_3541 {

static bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int FindMostFrequentVowelAndConsonantSolution::countingApproach(
    const std::string& s) {
  int vowelFreq[26] = {0};
  int consonantFreq[26] = {0};
  int maxVowel = 0;
  int maxConsonant = 0;

  for (char c : s) {
    int idx = c - 'a';
    if (isVowel(c)) {
      ++vowelFreq[idx];
      if (vowelFreq[idx] > maxVowel) {
        maxVowel = vowelFreq[idx];
      }
    } else {
      ++consonantFreq[idx];
      if (consonantFreq[idx] > maxConsonant) {
        maxConsonant = consonantFreq[idx];
      }
    }
  }

  return maxVowel + maxConsonant;
}

FindMostFrequentVowelAndConsonantSolution::
    FindMostFrequentVowelAndConsonantSolution() {
  this->setMetaInfo({
      .id = 3541,
      .title = "Find Most Frequent Vowel and Consonant",
      .url = "https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/",
  });
  this->registerStrategy(
      {
          .name = "CountingApproach",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(1)",
          .tags = {"Hash Table", "String", "Counting"},
      },
      countingApproach);
}

int FindMostFrequentVowelAndConsonantSolution::maxFreqSum(
    const std::string& s) {
  return this->getSolution()(s);
}

}  // namespace problem_3541
}  // namespace leetcode
