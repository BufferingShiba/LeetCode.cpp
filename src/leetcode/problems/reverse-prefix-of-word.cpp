#include "leetcode/problems/reverse-prefix-of-word.h"

namespace leetcode::problem_2000 {
namespace {

std::string reversePrefixImpl(std::string word, char ch) {
  auto pos = word.find(ch);
  if (pos == std::string::npos) {
    return word;
  }
  int left = 0;
  int right = static_cast<int>(pos);
  while (left < right) {
    std::swap(word[left], word[right]);
    ++left;
    --right;
  }
  return word;
}

}  // namespace

ReversePrefixOfWordSolution::ReversePrefixOfWordSolution() {
  setMetaInfo({.id = 2000,
               .title = "Reverse Prefix of Word",
               .url = "https://leetcode.com/problems/reverse-prefix-of-word/"});
  registerStrategy(
      {"Two Pointers", "Accepted", "O(n)", "O(1)",
       std::vector<std::string>{"Two Pointers", "String"},
       "Find first occurrence of ch, then reverse prefix with two pointers."},
      reversePrefixImpl);
}

std::string ReversePrefixOfWordSolution::reversePrefix(std::string word,
                                                       char ch) {
  return getSolution()(std::move(word), ch);
}

}  // namespace leetcode::problem_2000
