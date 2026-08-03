#include "leetcode/problems/kth-distinct-string-in-an-array.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_2053 {

namespace {

std::string kthDistinctImpl(std::vector<std::string>& arr, int k) {
  std::unordered_map<std::string, int> count;
  for (const auto& s : arr) {
    ++count[s];
  }
  int seen = 0;
  for (const auto& s : arr) {
    if (count[s] == 1) {
      ++seen;
      if (seen == k) {
        return s;
      }
    }
  }
  return "";
}

}  // namespace

KthDistinctStringInAnArraySolution::KthDistinctStringInAnArraySolution() {
  setMetaInfo({.id = 2053,
               .title = "Kth Distinct String in an Array",
               .url = "https://leetcode.com/problems/kth-distinct-string-in-an-array/"});
  registerStrategy(
      {.name = "HashTableCounting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "String", "Counting"}},
      kthDistinctImpl);
}

std::string KthDistinctStringInAnArraySolution::kthDistinct(std::vector<std::string>& arr, int k) {
  return getSolution()(arr, k);
}

}  // namespace problem_2053
}  // namespace leetcode
