#include "leetcode/problems/k-th-symbol-in-grammar.h"

namespace leetcode {
namespace problem_779 {

static int kthGrammarImpl(int n, int k) {
  (void)n;  // n 不影响位运算解法
  // 答案等于 (k-1) 二进制中 1 的个数的奇偶性
  unsigned int x = static_cast<unsigned int>(k - 1);
  int parity = 0;
  while (x) {
    parity ^= 1;
    x &= x - 1;  // 清除最低位的 1
  }
  return parity;
}

KThSymbolInGrammarSolution::KThSymbolInGrammarSolution() {
  setMetaInfo({.id = 779,
               .title = "K-th Symbol in Grammar",
               .url = "https://leetcode.com/problems/k-th-symbol-in-grammar/"});
  registerStrategy(
      {.name = "BitManipulation",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Bit Manipulation", "Recursion"}},
      kthGrammarImpl);
}

int KThSymbolInGrammarSolution::kthGrammar(int n, int k) {
  return getSolution()(n, k);
}

}  // namespace problem_779
}  // namespace leetcode
