#include <algorithm>

#include "leetcode/problems/maximize-the-confusion-of-an-exam.h"

namespace leetcode {
namespace problem_2024 {

static int solution1(string answerKey, int k) {
  const int n = static_cast<int>(answerKey.size());
  auto maxWindow = [&](char target) -> int {
    int left = 0, maxLen = 0, changes = 0;
    for (int right = 0; right < n; ++right) {
      if (answerKey[right] != target) ++changes;
      while (changes > k) {
        if (answerKey[left] != target) --changes;
        ++left;
      }
      maxLen = std::max(maxLen, right - left + 1);
    }
    return maxLen;
  };
  return std::max(maxWindow('T'), maxWindow('F'));
}

MaximizeTheConfusionOfAnExamSolution::MaximizeTheConfusionOfAnExamSolution() {
  setMetaInfo({
      .id = 2024,
      .title = "Maximize the Confusion of an Exam",
      .url = "https://leetcode.com/problems/maximize-the-confusion-of-an-exam"
  });
  registerStrategy({.name = "Sliding Window"}, solution1);
}

int MaximizeTheConfusionOfAnExamSolution::maxConsecutiveAnswers(string answerKey, int k) {
  return getSolution()(answerKey, k);
}

}  // namespace problem_2024
}  // namespace leetcode
