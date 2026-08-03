#include "leetcode/problems/implement-magic-dictionary.h"

#include <string>

namespace leetcode::problem_676 {

void MagicDictionary::addVariants(const std::string& word) {
  for (std::size_t i = 0; i < word.size(); ++i) {
    std::string variant = word;
    variant[i] = '*';
    ++variantCount_[variant];
  }
}

void MagicDictionary::buildDict(const std::vector<std::string>& dictionary) {
  variantCount_.clear();
  words_.clear();
  for (const auto& word : dictionary) {
    words_.insert(word);
    addVariants(word);
  }
}

bool MagicDictionary::search(const std::string& searchWord) {
  for (std::size_t i = 0; i < searchWord.size(); ++i) {
    std::string variant = searchWord;
    variant[i] = '*';
    auto it = variantCount_.find(variant);
    if (it != variantCount_.end() &&
        (it->second > 1 || words_.find(searchWord) == words_.end())) {
      return true;
    }
  }
  return false;
}

}  // namespace leetcode::problem_676
