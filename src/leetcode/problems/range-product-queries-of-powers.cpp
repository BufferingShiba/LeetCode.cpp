#include "leetcode/problems/range-product-queries-of-powers.h"

namespace leetcode {
namespace problem_2438 {

namespace {

constexpr long long kMod = 1000000007LL;

long long ModPow(long long base, long long exp, long long mod) {
  long long result = 1 % mod;
  base %= mod;
  while (exp > 0) {
    if (exp & 1) {
      result = result * base % mod;
    }
    base = base * base % mod;
    exp >>= 1;
  }
  return result;
}

std::vector<int> productQueriesImpl(int n,
                                    std::vector<std::vector<int>>& queries) {
  // Decompose n into powers of 2 present in its binary representation.
  std::vector<long long> powers;
  for (int bit = 0; (1LL << bit) <= n; ++bit) {
    if (n & (1 << bit)) {
      powers.push_back(1LL << bit);
    }
  }

  // Prefix products: prefix[i] = product(powers[0..i-1]) % MOD.
  const int m = static_cast<int>(powers.size());
  std::vector<long long> prefix(m + 1, 1);
  for (int i = 0; i < m; ++i) {
    prefix[i + 1] = prefix[i] * powers[i] % kMod;
  }

  std::vector<int> answers;
  answers.reserve(queries.size());
  for (const auto& q : queries) {
    int left = q[0];
    int right = q[1];
    // answer = powers[left]*...*powers[right]
    //        = prefix[right+1] * inv(prefix[left]) mod MOD
    long long numerator = prefix[right + 1];
    long long invDenominator = ModPow(prefix[left], kMod - 2, kMod);
    answers.push_back(static_cast<int>(numerator * invDenominator % kMod));
  }
  return answers;
}

}  // namespace

RangeProductQueriesOfPowersSolution::RangeProductQueriesOfPowersSolution() {
  setMetaInfo({.id = 2438,
               .title = "Range Product Queries of Powers",
               .url = "https://leetcode.com/problems/range-product-queries-of-powers/"});
  registerStrategy({.name = "prefix-product",
                    .expected = "Accepted",
                    .time_complexity = "O(m + q)",
                    .space_complexity = "O(m)",
                    .tags = {"Array", "Bit Manipulation", "Prefix Sum"}},
                   productQueriesImpl);
}

std::vector<int> RangeProductQueriesOfPowersSolution::productQueries(
    int n, std::vector<std::vector<int>>& queries) {
  return getSolution()(n, queries);
}

}  // namespace problem_2438
}  // namespace leetcode
