#include "leetcode/problems/fair-distribution-of-cookies.h"

#include <algorithm>

namespace leetcode {
namespace problem_2305 {
namespace {

void backtrack(const std::vector<int>& cookies, int idx, int k,
               std::vector<int>& sums, int& best) {
  // 剪枝：当前最大不公平度已不可能优于 best
  int curMax = 0;
  for (int s : sums) curMax = std::max(curMax, s);
  if (curMax >= best) return;

  if (idx == static_cast<int>(cookies.size())) {
    best = std::min(best, curMax);
    return;
  }

  for (int i = 0; i < k; ++i) {
    sums[i] += cookies[idx];
    backtrack(cookies, idx + 1, k, sums, best);
    sums[i] -= cookies[idx];
    // 对称剪枝：如果这个孩子当前 sum 为 0 且分配后仍为 0（即索引>0 的空孩子），
    // 避免重复把同一袋分给不同的空孩子
    if (sums[i] == 0) break;
  }
}

}  // namespace

int distributeCookiesImpl(std::vector<int>& cookies, int k) {
  // 降序排列，让大饼干先分配，便于尽早剪枝
  std::sort(cookies.rbegin(), cookies.rend());

  std::vector<int> sums(k, 0);
  // 初始化一个较大的上界：所有饼干都给一个孩子
  int best = 0;
  for (int c : cookies) best += c;

  backtrack(cookies, 0, k, sums, best);
  return best;
}

FairDistributionOfCookiesSolution::FairDistributionOfCookiesSolution() {
  setMetaInfo({.id = 2305,
               .title = "Fair Distribution of Cookies",
               .url = "https://leetcode.com/problems/fair-distribution-of-cookies/"});
  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(n^k) worst, pruned; n<=8",
       .space_complexity = "O(k)",
       .tags = {"Backtracking", "Array"}},
      distributeCookiesImpl);
}

int FairDistributionOfCookiesSolution::distributeCookies(std::vector<int>& cookies, int k) {
  return getSolution()(cookies, k);
}

}  // namespace problem_2305
}  // namespace leetcode
