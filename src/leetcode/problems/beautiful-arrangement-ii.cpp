
#include "leetcode/problems/beautiful-arrangement-ii.h"

namespace leetcode {
namespace problem_667 {

// 贪心摆动构造：前 k 个元素交替取两端产生差值 k,k-1,...,1，
// 剩余元素递增填入（差值为 1，已在集合中）。
// 时间复杂度: O(n), 空间复杂度: O(n)
static vector<int> solution1(int n, int k) {
  vector<int> ans;
  ans.reserve(n);
  // 摆动部分：从 1 开始，交替取高值和低值，产生 k 个不同差值
  int lo = 1, hi = k + 1;
  while (lo <= hi) {
    ans.push_back(lo++);
    if (lo <= hi) ans.push_back(hi--);
  }
  // 剩余元素用 k+2, k+3, ..., n 递增填入（这些相邻差均为 1）
  for (int i = k + 2; i <= n; ++i) {
    ans.push_back(i);
  }
  return ans;
}

BeautifulArrangementIiSolution::BeautifulArrangementIiSolution() {
  setMetaInfo({.id = 667,
               .title = "Beautiful Arrangement II",
               .url = "https://leetcode.com/problems/beautiful-arrangement-ii"});
  registerStrategy(
      {.name = "Greedy Swing Construction",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Math", "Greedy"}},
      solution1);
}

vector<int> BeautifulArrangementIiSolution::constructArray(int n, int k) {
  return getSolution()(n, k);
}

}  // namespace problem_667
}  // namespace leetcode
