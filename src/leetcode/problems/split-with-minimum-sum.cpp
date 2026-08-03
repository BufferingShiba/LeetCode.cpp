#include "leetcode/problems/split-with-minimum-sum.h"

#include <string>
#include <vector>
#include <algorithm>

namespace leetcode {
namespace problem_2578 {
namespace {

int splitNumImpl(int num) {
  // 提取各位数字并排序
  std::vector<int> digits;
  while (num > 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  std::sort(digits.begin(), digits.end());

  // 贪心：排序后交替分配给两个数，让两数的各位尽量小且均衡
  int num1 = 0, num2 = 0;
  for (size_t i = 0; i < digits.size(); ++i) {
    if (i % 2 == 0) {
      num1 = num1 * 10 + digits[i];
    } else {
      num2 = num2 * 10 + digits[i];
    }
  }
  return num1 + num2;
}

}  // namespace

SplitWithMinimumSumSolution::SplitWithMinimumSumSolution() {
  setMetaInfo({.id = 2578,
               .title = "Split With Minimum Sum",
               .url = "https://leetcode.com/problems/split-with-minimum-sum/"});
  registerStrategy({.name = "greedy_sort",
                    .expected = "Accepted",
                    .time_complexity = "O(d log d)",
                    .space_complexity = "O(d)",
                    .tags = {"Math", "Greedy", "Sorting"}},
                   splitNumImpl);
}

int SplitWithMinimumSumSolution::splitNum(int num) {
  return getSolution()(num);
}

}  // namespace problem_2578
}  // namespace leetcode
