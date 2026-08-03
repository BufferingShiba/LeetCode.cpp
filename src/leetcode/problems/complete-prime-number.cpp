#include "leetcode/problems/complete-prime-number.h"

#include <vector>

namespace leetcode {
namespace problem_3765 {

namespace {

bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int d = 3; d * d <= n; d += 2) {
    if (n % d == 0) return false;
  }
  return true;
}

bool completePrimeImpl(int num) {
  // 计算 num 的位数
  int len = 0;
  int temp = num;
  while (temp > 0) {
    ++len;
    temp /= 10;
  }
  if (len == 0) return false;  // num == 0 (不在约束中，但安全处理)

  // 预计算 10 的幂次: pow10[k] = 10^k, k = 0..len
  std::vector<int> pow10(len + 1, 1);
  for (int i = 1; i <= len; ++i) {
    pow10[i] = pow10[i - 1] * 10;
  }

  // 检查所有前缀: 前 k 位, k = 1..len
  for (int k = 1; k <= len; ++k) {
    int prefix = num / pow10[len - k];
    if (!isPrime(prefix)) return false;
  }

  // 检查所有后缀: 后 k 位, k = 1..len
  for (int k = 1; k <= len; ++k) {
    int suffix = num % pow10[k];
    if (!isPrime(suffix)) return false;
  }

  return true;
}

}  // namespace

CompletePrimeNumberSolution::CompletePrimeNumberSolution() {
  setMetaInfo({.id = 3765,
               .title = "Complete Prime Number",
               .url = "https://leetcode.com/problems/complete-prime-number/"});
  registerStrategy({.name = "trial_division",
                    .expected = "Accepted",
                    .time_complexity = "O(D * sqrt(N))",
                    .space_complexity = "O(D)",
                    .tags = {"Math", "Enumeration", "Number Theory"}},
                   completePrimeImpl);
  setDefaultStrategy();
}

bool CompletePrimeNumberSolution::completePrime(int num) {
  return getSolution()(num);
}

}  // namespace problem_3765
}  // namespace leetcode
