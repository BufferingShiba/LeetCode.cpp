#include "leetcode/problems/merge-strings-alternately.h"

#include <string>

namespace leetcode {
namespace problem_1768 {

namespace {

std::string mergeAlternatelyImpl(const std::string& word1, const std::string& word2) {
  std::string result;
  result.reserve(word1.size() + word2.size());

  int i = 0, j = 0;
  while (i < static_cast<int>(word1.size()) && j < static_cast<int>(word2.size())) {
    result.push_back(word1[i++]);
    result.push_back(word2[j++]);
  }
  result.append(word1.begin() + i, word1.end());
  result.append(word2.begin() + j, word2.end());

  return result;
}

}  // namespace

MergeStringsAlternatelySolution::MergeStringsAlternatelySolution() {
  setMetaInfo({.id = 1768,
               .title = "Merge Strings Alternately",
               .url = "https://leetcode.com/problems/merge-strings-alternately/"});
  registerStrategy(
      {.name = "TwoPointersSimulation",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n + m)",
       .tags = {"Two Pointers", "String"}},
      [](std::string word1, std::string word2) -> std::string {
        return mergeAlternatelyImpl(word1, word2);
      });
}

std::string MergeStringsAlternatelySolution::mergeAlternately(std::string word1,
                                                             std::string word2) {
  return getSolution()(std::move(word1), std::move(word2));
}

}  // namespace problem_1768
}  // namespace leetcode
