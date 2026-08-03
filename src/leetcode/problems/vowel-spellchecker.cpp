#include "leetcode/problems/vowel-spellchecker.h"

#include <cctype>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace leetcode::problem_966 {
namespace {

const std::string kEmptyString;

inline bool isVowel(char c) {
  c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

inline std::string toLower(const std::string& s) {
  std::string res = s;
  for (auto& c : res) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }
  return res;
}

inline std::string toVowelKey(const std::string& s) {
  std::string res = toLower(s);
  for (auto& c : res) {
    if (isVowel(c)) {
      c = '*';
    }
  }
  return res;
}

std::vector<std::string> spellcheckerImpl(std::vector<std::string>& wordlist,
                                          std::vector<std::string>& queries) {
  std::unordered_map<std::string, std::string> exact;
  std::unordered_map<std::string, std::string> cap;
  std::unordered_map<std::string, std::string> vowel;

  exact.reserve(wordlist.size());
  cap.reserve(wordlist.size());
  vowel.reserve(wordlist.size());

  for (const auto& w : wordlist) {
    if (exact.find(w) == exact.end()) {
      exact[w] = w;
    }
    std::string lower = toLower(w);
    if (cap.find(lower) == cap.end()) {
      cap[lower] = w;
    }
    std::string vkey = toVowelKey(w);
    if (vowel.find(vkey) == vowel.end()) {
      vowel[vkey] = w;
    }
  }

  std::vector<std::string> result;
  result.reserve(queries.size());

  for (const auto& q : queries) {
    std::string ans;
    auto it = exact.find(q);
    if (it != exact.end()) {
      ans = it->second;
    } else {
      std::string lower = toLower(q);
      auto it2 = cap.find(lower);
      if (it2 != cap.end()) {
        ans = it2->second;
      } else {
        std::string vkey = toVowelKey(q);
        auto it3 = vowel.find(vkey);
        if (it3 != vowel.end()) {
          ans = it3->second;
        }
      }
    }
    result.push_back(ans);
  }
  return result;
}

}  // namespace

VowelSpellcheckerSolution::VowelSpellcheckerSolution() {
  setMetaInfo({966, "Vowel Spellchecker",
               "https://leetcode.com/problems/vowel-spellchecker/"});
  registerStrategy({.name = "ThreeMapHash", .expected = "Accepted",
                    .time_complexity = "O(N)", .space_complexity = "O(N)",
                    .tags = {"Array", "Hash Table", "String"}},
                   spellcheckerImpl);
}

std::vector<std::string> VowelSpellcheckerSolution::spellchecker(
    std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
  return getSolution()(wordlist, queries);
}

}  // namespace leetcode::problem_966
