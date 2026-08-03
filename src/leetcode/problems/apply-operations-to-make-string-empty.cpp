
#include "leetcode/problems/apply-operations-to-make-string-empty.h"

namespace leetcode {
namespace problem_3039 {

// 计数 + 最后一次出现位置
// 思路：每次操作删除每个字母的第一次出现，因此字母 c 会在第 k（k=1..freq[c]）次
// 操作中被删除。最后一次操作是第 maxFreq 次（maxFreq 为最大出现次数）。
// 只有 freq[c]==maxFreq 的字母，其最后一次出现会保留到最后一次操作之前。
// 将这些字母按其在原串中的最后一次出现位置依次收集，即为答案。
// 时间复杂度: O(n), 空间复杂度: O(1)
static string solution1(string s) {
  vector<int> count(26, 0);
  vector<int> lastPos(26, -1);
  const int n = s.size();
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    ++count[c];
    lastPos[c] = i;
  }

  int maxFreq = 0;
  for (int i = 0; i < 26; ++i) {
    if (count[i] > maxFreq) maxFreq = count[i];
  }

  string result;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    if (count[c] == maxFreq && lastPos[c] == i) {
      result.push_back(s[i]);
    }
  }
  return result;
}

ApplyOperationsToMakeStringEmptySolution::ApplyOperationsToMakeStringEmptySolution() {
  setMetaInfo({.id = 3039,
               .title = "Apply Operations to Make String Empty",
               .url = "https://leetcode.com/problems/apply-operations-to-make-string-empty"});
  registerStrategy({.name = "Counting & Last Position",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Hash Table", "Sorting", "Counting"}},
                   solution1);
}

string ApplyOperationsToMakeStringEmptySolution::lastNonEmptyString(string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3039
}  // namespace leetcode
