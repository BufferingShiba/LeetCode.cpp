#include "leetcode/problems/count-common-words-with-one-occurrence.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_2085 {

namespace {

int countWordsImpl(std::vector<std::string>& words1,
                   std::vector<std::string>& words2) {
  std::unordered_map<std::string, int> cnt1;
  std::unordered_map<std::string, int> cnt2;
  for (const auto& w : words1) {
    ++cnt1[w];
  }
  for (const auto& w : words2) {
    ++cnt2[w];
  }
  int result = 0;
  for (const auto& kv : cnt1) {
    if (kv.second == 1 && cnt2[kv.first] == 1) {
      ++result;
    }
  }
  return result;
}

}  // namespace

CountCommonWordsWithOneOccurrenceSolution::CountCommonWordsWithOneOccurrenceSolution() {
  setMetaInfo({.id = 2085,
               .title = "Count Common Words With One Occurrence",
               .url = "https://leetcode.com/problems/count-common-words-with-one-occurrence/"});
  registerStrategy(
      {"HashTable Counting", "Accepted", "O(n)", "O(n)",
       {"Array", "Hash Table", "String", "Counting"}},
      countWordsImpl);
}

int CountCommonWordsWithOneOccurrenceSolution::countWords(
    std::vector<std::string>& words1, std::vector<std::string>& words2) {
  return getSolution()(words1, words2);
}

}  // namespace problem_2085
}  // namespace leetcode
