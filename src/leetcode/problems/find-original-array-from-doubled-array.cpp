#include "leetcode/problems/find-original-array-from-doubled-array.h"

namespace leetcode::problem_2007 {

static std::vector<int> findOriginalArrayImpl(std::vector<int>& changed) {
  int n = changed.size();
  if (n % 2 == 1) return {};

  constexpr int kMaxVal = 100000;
  std::vector<int> freq(2 * kMaxVal + 1, 0);
  for (int x : changed) {
    freq[x]++;
  }

  std::vector<int> result;
  result.reserve(n / 2);

  for (int x = 0; x <= kMaxVal; ++x) {
    if (freq[x] == 0) continue;

    if (x == 0) {
      if (freq[0] % 2 == 1) return {};
      result.insert(result.end(), freq[0] / 2, 0);
      freq[0] = 0;
      continue;
    }

    int cnt = freq[x];
    int doubled = 2 * x;
    if (freq[doubled] < cnt) {
      return {};
    }
    freq[doubled] -= cnt;
    result.insert(result.end(), cnt, x);
  }

  return result;
}

FindOriginalArrayFromDoubledArraySolution::FindOriginalArrayFromDoubledArraySolution() {
  setMetaInfo({.id = 2007,
               .title = "Find Original Array From Doubled Array",
               .url = "https://leetcode.com/problems/find-original-array-from-doubled-array/"});
  registerStrategy(
      {.name = "FrequencyArray",
       .expected = "Accepted",
       .time_complexity = "O(N + K)",
       .space_complexity = "O(K)",
       .tags = {"Array", "Hash Table", "Greedy", "Sorting"}},
      findOriginalArrayImpl);
}

std::vector<int> FindOriginalArrayFromDoubledArraySolution::findOriginalArray(
    std::vector<int>& changed) {
  return getSolution()(changed);
}

}  // namespace leetcode::problem_2007
