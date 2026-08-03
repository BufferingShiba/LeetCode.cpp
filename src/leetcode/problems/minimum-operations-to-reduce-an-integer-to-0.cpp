#include "leetcode/problems/minimum-operations-to-reduce-an-integer-to-0.h"

namespace leetcode {
namespace problem_2571 {

namespace {

int minOperationsImpl(int n) {
  int ans = 0;
  while (n > 0) {
    if ((n & (n - 1)) == 0) {  // n is a power of 2 (single set bit)
      ++ans;
      break;
    }
    int lb = n & (-n);          // lowest set bit
    if (n & (lb << 1)) {
      n += lb;                  // carry: clear a run of consecutive 1 bits
    } else {
      n -= lb;                  // remove the isolated lowest set bit
    }
    ++ans;
  }
  return ans;
}

}  // namespace

MinimumOperationsToReduceAnIntegerTo0Solution::
    MinimumOperationsToReduceAnIntegerTo0Solution() {
  setMetaInfo({.id = 2571,
               .title = "Minimum Operations to Reduce an Integer to 0",
               .url = "https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/"});

  registerStrategy(
      {"greedyBitManipulation", "Accepted", "O(log n)", "O(1)",
       {"Greedy", "Bit Manipulation"}},
      static_cast<int (*)(int)>(&minOperationsImpl));
}

int MinimumOperationsToReduceAnIntegerTo0Solution::minOperations(int n) {
  return getSolution()(n);
}

}  // namespace problem_2571
}  // namespace leetcode
