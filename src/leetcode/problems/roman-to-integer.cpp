#include "leetcode/problems/roman-to-integer.h"

#include <string>
#include <unordered_map>

namespace leetcode {
namespace problem_13 {
namespace {

int romanToIntImpl(std::string s) {
  static const std::unordered_map<char, int> values = {
      {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000}};
  int result = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    int current = values.at(s[i]);
    if (i + 1 < s.size() && current < values.at(s[i + 1])) {
      result -= current;
    } else {
      result += current;
    }
  }
  return result;
}

}  // namespace

RomanToIntegerSolution::RomanToIntegerSolution() {
  setMetaInfo({.id = 13,
               .title = "Roman to Integer",
               .url = "https://leetcode.com/problems/roman-to-integer/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Hash Table", "Math"}},
      romanToIntImpl);
}

int RomanToIntegerSolution::romanToInt(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_13
}  // namespace leetcode
