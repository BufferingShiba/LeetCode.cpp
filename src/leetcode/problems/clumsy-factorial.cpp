#include "leetcode/problems/clumsy-factorial.h"

namespace leetcode {
namespace problem_1006 {

// Clumsy factorial equals n*(n-1)/(n-2)+(n-3)-(n-4)*(n-5)/(n-6)+...
// The * and / are grouped into blocks processed left-to-right, and the blocks
// are summed with + / - signs. Use a stack to accumulate each block's value.
static int solution1(int n) {
  int current = n;  // running value of the current * / block (sign included)
  std::vector<int> stack;
  stack.push_back(current);

  // op index between consecutive numbers: 0:'*', 1:'/', 2:'+', 3:'-' (cyclic)
  int idx = 0;
  for (int i = n - 1; i >= 1; --i) {
    switch (idx % 4) {
      case 0:  // multiply
        current *= i;
        stack.back() = current;
        break;
      case 1:  // integer floor division
        current /= i;
        stack.back() = current;
        break;
      case 2:  // plus: starts a new positive block
        current = i;
        stack.push_back(i);
        break;
      default:  // minus: starts a new negative block
        current = -i;
        stack.push_back(-i);
        break;
    }
    ++idx;
  }

  int sum = 0;
  for (int v : stack) sum += v;
  return sum;
}

ClumsyFactorialSolution::ClumsyFactorialSolution() {
  setMetaInfo({
      .id = 1006,
      .title = "Clumsy Factorial",
      .url = "https://leetcode.com/problems/clumsy-factorial"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

int ClumsyFactorialSolution::clumsy(int n) {
  return getSolution()(n);
}

}  // namespace problem_1006
}  // namespace leetcode
