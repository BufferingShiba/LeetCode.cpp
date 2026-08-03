#include "leetcode/problems/detect-capital.h"

namespace leetcode {
namespace problem_520 {

static bool detectCapitalUseImpl(std::string word) {
  int n = word.size();
  int caps = 0;
  for (char c : word) {
    if (c >= 'A' && c <= 'Z') ++caps;
  }
  if (caps == 0) return true;
  if (caps == n) return true;
  if (caps == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;
  return false;
}

DetectCapitalSolution::DetectCapitalSolution() {
  setMetaInfo({.id = 520, .title = "Detect Capital", .url = "https://leetcode.com/problems/detect-capital/"});
  registerStrategy({
    .name = "CountCaps",
    .expected = "Accepted",
    .time_complexity = "O(n)",
    .space_complexity = "O(1)",
    .tags = {"String"}
  }, detectCapitalUseImpl);
  setDefaultStrategy();
}

bool DetectCapitalSolution::detectCapitalUse(std::string word) {
  return getSolution()(word);
}

}  // namespace problem_520
}  // namespace leetcode
