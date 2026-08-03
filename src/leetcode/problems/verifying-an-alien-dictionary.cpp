#include "leetcode/problems/verifying-an-alien-dictionary.h"

namespace leetcode::problem_953 {
namespace {

bool isAlienSortedImpl(std::vector<std::string>& words, std::string order) {
  int rank[26];
  for (int i = 0; i < 26; ++i) {
    rank[order[i] - 'a'] = i;
  }

  for (size_t i = 0; i + 1 < words.size(); ++i) {
    const std::string& a = words[i];
    const std::string& b = words[i + 1];
    size_t len = a.size() < b.size() ? a.size() : b.size();
    bool compared = false;
    for (size_t j = 0; j < len; ++j) {
      if (a[j] != b[j]) {
        if (rank[a[j] - 'a'] > rank[b[j] - 'a']) {
          return false;
        }
        compared = true;
        break;
      }
    }
    if (!compared && a.size() > b.size()) {
      return false;
    }
  }
  return true;
}

}  // namespace

VerifyingAnAlienDictionarySolution::VerifyingAnAlienDictionarySolution() {
  setMetaInfo({.id = 953,
               .title = "Verifying an Alien Dictionary",
               .url = "https://leetcode.com/problems/verifying-an-alien-dictionary/"});
  registerStrategy({.name = "Rank-Map",
                    .expected = "Accepted",
                    .time_complexity = "O(N*L)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Hash Table", "String"}},
                   isAlienSortedImpl);
}

bool VerifyingAnAlienDictionarySolution::isAlienSorted(std::vector<std::string>& words,
                                                        std::string order) {
  return getSolution()(words, std::move(order));
}

}  // namespace leetcode::problem_953
