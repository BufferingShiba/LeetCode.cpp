#include "leetcode/problems/decode-the-message.h"

#include <array>
#include <string>

namespace leetcode {
namespace problem_2325 {

namespace {

std::string decodeMessageImpl(std::string key, std::string message) {
  std::array<char, 26> table{};
  std::array<bool, 26> used{};
  int idx = 0;
  for (char c : key) {
    if (c == ' ') continue;
    int pos = c - 'a';
    if (!used[pos]) {
      used[pos] = true;
      table[pos] = static_cast<char>('a' + idx);
      ++idx;
    }
  }
  std::string res;
  res.reserve(message.size());
  for (char c : message) {
    if (c == ' ') {
      res.push_back(' ');
    } else {
      res.push_back(table[c - 'a']);
    }
  }
  return res;
}

}  // namespace

DecodeTheMessageSolution::DecodeTheMessageSolution() {
  setMetaInfo({.id = 2325,
               .title = "Decode the Message",
               .url = "https://leetcode.com/problems/decode-the-message/"});
  registerStrategy(
      {.name = "HashTableSubstitution",
       .expected = "Accepted",
       .time_complexity = "O(|key| + |message|)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String"}},
      decodeMessageImpl);
}

std::string DecodeTheMessageSolution::decodeMessage(std::string key,
                                                    std::string message) {
  return getSolution()(std::move(key), std::move(message));
}

}  // namespace problem_2325
}  // namespace leetcode
