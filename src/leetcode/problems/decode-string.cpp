#include "leetcode/problems/decode-string.h"

#include <cctype>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_394 {

static string solution1(string s) {
  string result;
  // stack of pairs (count, prefix_before_bracket)
  std::vector<std::pair<int, std::string>> stack;
  int num = 0;
  std::string current;
  for (char c : s) {
    if (std::isdigit(c)) {
      num = num * 10 + (c - '0');
    } else if (c == '[') {
      stack.emplace_back(num, std::move(current));
      num = 0;
      current.clear();
    } else if (c == ']') {
      auto [count, prefix] = stack.back();
      stack.pop_back();
      std::string repeated;
      repeated.reserve(current.size() * count);
      for (int i = 0; i < count; ++i) repeated += current;
      current = prefix + repeated;
    } else {
      current.push_back(c);
    }
  }
  result = current;
  (void)result;
  return result;
}

DecodeStringSolution::DecodeStringSolution() {
  setMetaInfo({
      .id = 394,
      .title = "Decode String",
      .url = "https://leetcode.com/problems/decode-string"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

string DecodeStringSolution::decodeString(string s) {
  return getSolution()(s);
}

}  // namespace problem_394
}  // namespace leetcode
