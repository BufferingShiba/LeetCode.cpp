#include "leetcode/problems/valid-anagram.h"

#include <array>
#include <string>

namespace leetcode {
namespace problem_242 {

namespace {

bool isAnagramImpl(std::string s, std::string t) {
  if (s.size() != t.size()) {
    return false;
  }
  std::array<int, 26> count{};
  for (char c : s) {
    ++count[c - 'a'];
  }
  for (char c : t) {
    if (--count[c - 'a'] < 0) {
      return false;
    }
  }
  return true;
}

}  // namespace

ValidAnagramSolution::ValidAnagramSolution() {
  setMetaInfo({
      .id = 242,
      .title = "Valid Anagram",
      .url = "https://leetcode.com/problems/valid-anagram/",
  });
  registerStrategy(
      {
          .name = "CountArray",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(1)",
          .tags = {"Hash Table", "String", "Sorting"},
      },
      isAnagramImpl);
}

bool ValidAnagramSolution::isAnagram(std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace problem_242
}  // namespace leetcode
