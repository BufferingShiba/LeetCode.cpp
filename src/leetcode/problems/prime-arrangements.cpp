#include "leetcode/problems/prime-arrangements.h"

namespace leetcode {
namespace problem_1175 {
namespace {

constexpr long long kMod = 1000000007LL;

bool isPrime(int x) {
  if (x < 2) return false;
  for (int d = 2; d * d <= x; ++d) {
    if (x % d == 0) return false;
  }
  return true;
}

long long factorialMod(int x) {
  long long res = 1;
  for (int i = 2; i <= x; ++i) {
    res = (res * i) % kMod;
  }
  return res;
}

int numPrimeArrangementsImpl(int n) {
  int primeCount = 0;
  for (int i = 1; i <= n; ++i) {
    if (isPrime(i)) ++primeCount;
  }
  int compositeCount = n - primeCount;
  long long ans = factorialMod(primeCount) * factorialMod(compositeCount) % kMod;
  return static_cast<int>(ans);
}

}  // namespace

PrimeArrangementsSolution::PrimeArrangementsSolution() {
  setMetaInfo({.id = 1175,
               .title = "Prime Arrangements",
               .url = "https://leetcode.com/problems/prime-arrangements/"});
  registerStrategy({.name = "CountingAndFactorial",
                    .expected = "Accepted",
                    .time_complexity = "O(n sqrt(n))",
                    .space_complexity = "O(1)",
                    .tags = {"Math"}},
                   numPrimeArrangementsImpl);
}

int PrimeArrangementsSolution::numPrimeArrangements(int n) {
  return getSolution()(n);
}

}  // namespace problem_1175
}  // namespace leetcode
