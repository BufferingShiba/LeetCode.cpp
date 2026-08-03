#include "leetcode/problems/vowels-of-all-substrings.h"

namespace leetcode::problem_2063 {
namespace {

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Contribution method: each vowel at position i belongs to (i+1) * (n-i)
// substrings (choose left endpoint from [0..i] and right endpoint from [i..n-1]).
long long countVowelsContribution(const std::string& word) {
  const std::size_t n = word.size();
  long long total = 0;
  for (std::size_t i = 0; i < n; ++i) {
    if (isVowel(word[i])) {
      total += static_cast<long long>(i + 1) * static_cast<long long>(n - i);
    }
  }
  return total;
}

}  // namespace

VowelsOfAllSubstringsSolution::VowelsOfAllSubstringsSolution() {
  setMetaInfo({.id = 2063,
               .title = "Vowels of All Substrings",
               .url = "https://leetcode.com/problems/vowels-of-all-substrings/"});

  registerStrategy(
      {.name = "ContributionPerPosition",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String", "Combinatorics"}},
      countVowelsContribution);
}

long long VowelsOfAllSubstringsSolution::countVowels(const std::string& word) {
  return getSolution()(word);
}

}  // namespace leetcode::problem_2063
