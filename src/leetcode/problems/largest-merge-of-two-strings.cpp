#include "leetcode/problems/largest-merge-of-two-strings.h"

#include <string>

namespace leetcode {
namespace problem_1754 {
namespace {

std::string largestMergeImpl(std::string word1, std::string word2) {
  std::string merge;
  merge.reserve(word1.size() + word2.size());
  size_t i = 0, j = 0;
  while (i < word1.size() && j < word2.size()) {
    // Pick from the string whose remaining suffix is lexicographically larger.
    if (word1.compare(i, word1.size() - i, word2, j, word2.size() - j) > 0) {
      merge.push_back(word1[i++]);
    } else {
      merge.push_back(word2[j++]);
    }
  }
  merge.append(word1, i, std::string::npos);
  merge.append(word2, j, std::string::npos);
  return merge;
}

}  // namespace

std::string LargestMergeOfTwoStringsSolution::largestMerge(std::string word1,
                                                           std::string word2) {
  return getSolution()(std::move(word1), std::move(word2));
}

LargestMergeOfTwoStringsSolution::LargestMergeOfTwoStringsSolution() {
  setMetaInfo(
      {.id = 1754,
       .title = "Largest Merge Of Two Strings",
       .url = "https://leetcode.com/problems/largest-merge-of-two-strings/"});
  registerStrategy({.name = "greedy_compare",
                    .expected = "Accepted",
                    .time_complexity = "O(n*m)",
                    .space_complexity = "O(1)",
                    .tags = {"Two Pointers", "String", "Greedy"}},
                   largestMergeImpl);
}

}  // namespace problem_1754
}  // namespace leetcode
