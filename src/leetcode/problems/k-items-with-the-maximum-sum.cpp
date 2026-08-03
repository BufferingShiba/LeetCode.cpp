#include <algorithm>

#include "leetcode/problems/k-items-with-the-maximum-sum.h"

namespace leetcode {
namespace problem_2600 {
namespace {

int kItemsWithMaximumSumImpl(int numOnes, int numZeros, int numNegOnes, int k) {
  int sum = 0;
  // 优先取 1
  int takeOnes = std::min(numOnes, k);
  sum += takeOnes;
  k -= takeOnes;
  // 再取 0（不影响和）
  int takeZeros = std::min(numZeros, k);
  k -= takeZeros;
  // 最后取 -1
  sum -= k;
  return sum;
}

}  // namespace

KItemsWithTheMaximumSumSolution::KItemsWithTheMaximumSumSolution() {
  setMetaInfo({.id = 2600,
               .title = "K Items With the Maximum Sum",
               .url = "https://leetcode.com/problems/k-items-with-the-maximum-sum/"});
  registerStrategy(
      {.name = "greedy",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Greedy"}},
      kItemsWithMaximumSumImpl);
}

int KItemsWithTheMaximumSumSolution::kItemsWithMaximumSum(int numOnes,
                                                          int numZeros,
                                                          int numNegOnes,
                                                          int k) {
  return getSolution()(numOnes, numZeros, numNegOnes, k);
}

}  // namespace problem_2600
}  // namespace leetcode
