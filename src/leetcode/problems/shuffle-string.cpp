#include "leetcode/problems/shuffle-string.h"

namespace leetcode::problem_1528 {

namespace {

std::string restoreStringImpl(std::string s, std::vector<int>& indices) {
  std::string result(s.size(), ' ');
  for (std::size_t i = 0; i < s.size(); ++i) {
    result[static_cast<std::size_t>(indices[i])] = s[i];
  }
  return result;
}

}  // namespace

ShuffleStringSolution::ShuffleStringSolution() {
  setMetaInfo({.id = 1528,
               .title = "Shuffle String",
               .url = "https://leetcode.com/problems/shuffle-string/"});

  registerStrategy({.name = "DirectPlacement",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "String"}},
                   restoreStringImpl);
}

std::string ShuffleStringSolution::restoreString(std::string s,
                                                 std::vector<int>& indices) {
  return getSolution()(std::move(s), indices);
}

}  // namespace leetcode::problem_1528
