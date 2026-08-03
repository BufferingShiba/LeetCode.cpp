#include "leetcode/problems/find-good-days-to-rob-the-bank.h"

#include <vector>

namespace leetcode {
namespace problem_2100 {

static std::vector<int> goodDaysToRobBankImpl(std::vector<int>& security,
                                               int time) {
  int n = static_cast<int>(security.size());
  std::vector<int> result;

  if (n == 0) return result;

  // left[i] = 以 i 结尾的连续非递增段长度（包含 i 本身不算，只算前面的对数）
  // 实际上 left[i] 表示从 i 往左最多连续满足 security[j] >= security[j+1] 的步数
  std::vector<int> left(n, 0);
  for (int i = 1; i < n; ++i) {
    if (security[i - 1] >= security[i]) {
      left[i] = left[i - 1] + 1;
    } else {
      left[i] = 0;
    }
  }

  // right[i] = 从 i 往右最多连续满足 security[j] <= security[j+1] 的步数
  std::vector<int> right(n, 0);
  for (int i = n - 2; i >= 0; --i) {
    if (security[i] <= security[i + 1]) {
      right[i] = right[i + 1] + 1;
    } else {
      right[i] = 0;
    }
  }

  // 检查每个可能的位置
  for (int i = time; i < n - time; ++i) {
    if (left[i] >= time && right[i] >= time) {
      result.push_back(i);
    }
  }

  return result;
}

FindGoodDaysToRobTheBankSolution::FindGoodDaysToRobTheBankSolution() {
  setMetaInfo({.id = 2100,
               .title = "Find Good Days to Rob the Bank",
               .url = "https://leetcode.com/problems/find-good-days-to-rob-the-bank/"});

  registerStrategy(
      {.name = "Prefix DP",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Dynamic Programming", "Prefix Sum"}},
      goodDaysToRobBankImpl);
}

std::vector<int> FindGoodDaysToRobTheBankSolution::goodDaysToRobBank(
    std::vector<int>& security, int time) {
  return getSolution()(security, time);
}

}  // namespace problem_2100
}  // namespace leetcode
