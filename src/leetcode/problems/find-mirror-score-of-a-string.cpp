#include "leetcode/problems/find-mirror-score-of-a-string.h"

#include <vector>

namespace leetcode {
namespace problem_3412 {

static long solution1(string s) {
  // Stack per letter, holding indices of unmarked positions that
  // are available to be matched as the "mirror" counterpart later.
  std::vector<std::vector<int>> stacks(26);
  long score = 0;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    int mirror = 'z' - (s[i] - 'a');  // ASCII of mirror ('a'+'z' - s[i])
    auto& st = stacks[mirror - 'a'];
    if (!st.empty()) {
      int j = st.back();
      st.pop_back();
      score += static_cast<long>(i - j);
    } else {
      stacks[s[i] - 'a'].push_back(i);
    }
  }
  return score;
}

FindMirrorScoreOfAStringSolution::FindMirrorScoreOfAStringSolution() {
  setMetaInfo({
      .id = 3412,
      .title = "Find Mirror Score of a String",
      .url = "https://leetcode.com/problems/find-mirror-score-of-a-string"
  });
  registerStrategy(
      {
          .name = "Stacks per Letter",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(n)",
          .tags = {"stack"},
      },
      solution1);
}

long FindMirrorScoreOfAStringSolution::calculateScore(string s) {
  return getSolution()(s);
}

}  // namespace problem_3412
}  // namespace leetcode
