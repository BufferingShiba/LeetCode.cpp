#include "leetcode/problems/find-resultant-array-after-removing-anagrams.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2273 {
namespace {

std::vector<std::string> removeAnagramsImpl(std::vector<std::string>& words) {
  std::vector<std::string> result;
  std::string prevSorted;  // sorted chars of the last kept word's original
  for (std::string& word : words) {
    std::string sorted = word;
    std::sort(sorted.begin(), sorted.end());
    if (result.empty() || sorted != prevSorted) {
      result.push_back(word);
      prevSorted = std::move(sorted);
    }
  }
  return result;
}

}  // namespace

FindResultantArrayAfterRemovingAnagramsSolution::
    FindResultantArrayAfterRemovingAnagramsSolution() {
  setMetaInfo(
      {.id = 2273,
       .title = "Find Resultant Array After Removing Anagrams",
       .url = "https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/"});

  registerStrategy(
      {.name = "AdjacentAnagramScan",
       .expected = "Accepted",
       .time_complexity = "O(n * k log k)",
       .space_complexity = "O(k)",
       .tags = {"Array", "String", "Sorting"}},
      removeAnagramsImpl);
}

std::vector<std::string>
FindResultantArrayAfterRemovingAnagramsSolution::removeAnagrams(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_2273
}  // namespace leetcode
