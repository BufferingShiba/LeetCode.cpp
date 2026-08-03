#include "leetcode/problems/to-lower-case.h"

#include <string>

namespace leetcode {
namespace problem_709 {

namespace {

std::string toLowerCaseImpl(std::string s) {
  for (char& c : s) {
    if (c >= 'A' && c <= 'Z') {
      c = static_cast<char>(c + ('a' - 'A'));
    }
  }
  return s;
}

}  // namespace

ToLowerCaseSolution::ToLowerCaseSolution() {
  setMetaInfo({.id = 709, .title = "To Lower Case", .url = "https://leetcode.com/problems/to-lower-case/"});
  registerStrategy(
      {.name = "iterate_and_convert",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String"}},
      toLowerCaseImpl);
}

std::string ToLowerCaseSolution::toLowerCase(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_709
}  // namespace leetcode
