#include "leetcode/problems/shifting-letters-ii.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2381 {

static std::string shiftingLettersImpl(std::string s,
                                       std::vector<std::vector<int>>& shifts) {
  const int n = static_cast<int>(s.size());
  std::vector<int> diff(n + 1, 0);

  for (const auto& sh : shifts) {
    int start = sh[0];
    int end = sh[1];
    int delta = (sh[2] == 1) ? 1 : -1;
    diff[start] += delta;
    diff[end + 1] -= delta;
  }

  int net = 0;
  for (int i = 0; i < n; ++i) {
    net += diff[i];
    int shift_amount = net % 26;
    if (shift_amount < 0) {
      shift_amount += 26;
    }
    s[i] = static_cast<char>('a' + (s[i] - 'a' + shift_amount) % 26);
  }

  return s;
}

ShiftingLettersIiSolution::ShiftingLettersIiSolution() {
  setMetaInfo({.id = 2381,
               .title = "Shifting Letters II",
               .url = "https://leetcode.com/problems/shifting-letters-ii/"});
  registerStrategy(
      {.name = "DifferenceArray",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n)",
       .tags = {"Array", "String", "Prefix Sum"}},
      shiftingLettersImpl);
}

std::string ShiftingLettersIiSolution::shiftingLetters(
    std::string s, std::vector<std::vector<int>>& shifts) {
  return getSolution()(s, shifts);
}

}  // namespace problem_2381
}  // namespace leetcode
