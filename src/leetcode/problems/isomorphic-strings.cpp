#include "leetcode/problems/isomorphic-strings.h"

#include <string>
#include <unordered_map>

namespace leetcode {
namespace problem_205 {
namespace {

bool isIsomorphicImpl(const std::string& s, const std::string& t) {
  std::unordered_map<char, char> s_to_t;
  std::unordered_map<char, char> t_to_s;
  for (std::size_t i = 0; i < s.size(); ++i) {
    char sc = s[i];
    char tc = t[i];

    auto sit = s_to_t.find(sc);
    if (sit != s_to_t.end()) {
      if (sit->second != tc) return false;
    } else {
      auto tit = t_to_s.find(tc);
      if (tit != t_to_s.end()) return false;  // 目标已被占用
      s_to_t[sc] = tc;
      t_to_s[tc] = sc;
    }
  }
  return true;
}

}  // namespace

IsomorphicStringsSolution::IsomorphicStringsSolution() {
  setMetaInfo({.id = 205,
               .title = "Isomorphic Strings",
               .url = "https://leetcode.com/problems/isomorphic-strings/"});
  registerStrategy(
      {.name = "double_hash_map",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String"}},
      isIsomorphicImpl);
}

bool IsomorphicStringsSolution::isIsomorphic(std::string s, std::string t) {
  return getSolution()(s, t);
}

}  // namespace problem_205
}  // namespace leetcode
