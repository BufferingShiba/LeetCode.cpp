#include "leetcode/problems/keyboard-row.h"

#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::problem_500 {

namespace {

const std::unordered_map<char, int> kRowMap = [] {
  std::unordered_map<char, int> m;
  const std::string row1 = "qwertyuiop";
  const std::string row2 = "asdfghjkl";
  const std::string row3 = "zxcvbnm";
  for (char c : row1) m.emplace(c, 0);
  for (char c : row2) m.emplace(c, 1);
  for (char c : row3) m.emplace(c, 2);
  return m;
}();

std::vector<std::string> findWordsImpl(std::vector<std::string>& words) {
  using Map = std::unordered_map<char, int>;
  std::vector<std::string> result;
  for (const std::string& w : words) {
    bool allSame = true;
    for (std::size_t i = 0; i < w.size(); ++i) {
      const char lower = static_cast<char>(std::tolower(static_cast<unsigned char>(w[i])));
      const int row = kRowMap.at(lower);
      if (i > 0) {
        const char prevLower =
            static_cast<char>(std::tolower(static_cast<unsigned char>(w[i - 1])));
        if (kRowMap.at(prevLower) != row) {
          allSame = false;
          break;
        }
      }
    }
    if (allSame) result.push_back(w);
  }
  return result;
}

}  // namespace

KeyboardRowSolution::KeyboardRowSolution() {
  setMetaInfo({.id = 500, .title = "Keyboard Row", .url = "https://leetcode.com/problems/keyboard-row/"});
  registerStrategy({.name = "hash-map-row", .expected = "Accepted", .time_complexity = "O(n*m)", .space_complexity = "O(1)", .tags = {"Array", "Hash Table", "String"}}, findWordsImpl);
}

std::vector<std::string> KeyboardRowSolution::findWords(std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace leetcode::problem_500
