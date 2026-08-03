#include "leetcode/problems/smallest-substring-with-identical-characters-ii.h"

#include <algorithm>

namespace leetcode {
namespace problem_3399 {

namespace {

int alternatingOperations(const std::string& s, char first) {
  int operations = 0;
  for (std::size_t i = 0; i < s.size(); ++i) {
    const char expected = (i % 2 == 0) ? first : (first == '0' ? '1' : '0');
    operations += s[i] != expected;
  }
  return operations;
}

int operationsForLimit(const std::string& s, int limit) {
  if (limit == 1) {
    return std::min(alternatingOperations(s, '0'),
                    alternatingOperations(s, '1'));
  }

  int operations = 0;
  for (std::size_t i = 0; i < s.size();) {
    std::size_t j = i + 1;
    while (j < s.size() && s[j] == s[i]) {
      ++j;
    }
    operations += static_cast<int>((j - i) / (limit + 1));
    i = j;
  }
  return operations;
}

int minLengthImpl(std::string& s, int numOps) {
  int low = 1;
  int high = static_cast<int>(s.size());
  while (low < high) {
    const int middle = low + (high - low) / 2;
    if (operationsForLimit(s, middle) <= numOps) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  return low;
}

}  // namespace

SmallestSubstringWithIdenticalCharactersIiSolution::
    SmallestSubstringWithIdenticalCharactersIiSolution() {
  setMetaInfo({
      .id = 3399,
      .title = "Smallest Substring With Identical Characters II",
      .url =
          "https://leetcode.com/problems/smallest-substring-with-identical-characters-ii/"});
  registerStrategy({.name = "binary-search-with-run-greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Binary Search", "Greedy"},
                    .notes =
                        "Handle limit one as an alternating-string problem; for larger "
                        "limits, count one flip per complete block of limit+1 equal chars."},
                   minLengthImpl);
}

int SmallestSubstringWithIdenticalCharactersIiSolution::minLength(
    std::string s, int numOps) {
  return getSolution()(s, numOps);
}

}  // namespace problem_3399
}  // namespace leetcode
