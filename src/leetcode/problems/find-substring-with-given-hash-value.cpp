#include "leetcode/problems/find-substring-with-given-hash-value.h"

#include <string>

namespace leetcode::problem_2156 {

namespace {

// Compute (base^exp) % mod using fast exponentiation.
long long modPow(long long base, long long exp, long long mod) {
  if (mod == 1) return 0;
  long long result = 1 % mod;
  base %= mod;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}

std::string subStrHashImpl(const std::string& s, int power, int modulo, int k,
                           int hashValue) {
  int n = static_cast<int>(s.size());
  long long p = power;
  long long m = modulo;

  // Precompute p^(k-1) mod m.
  long long p_pow_k1 = modPow(p, k - 1, m);

  // Compute hash of the rightmost window s[n-k .. n-1] in O(k).
  long long cur_hash = 0;
  long long cur_pow = 1;
  for (int i = n - k; i < n; ++i) {
    int val = s[i] - 'a' + 1;
    cur_hash = (cur_hash + val * cur_pow) % m;
    cur_pow = (cur_pow * p) % m;
  }

  int best_start = -1;
  if (cur_hash == hashValue) {
    best_start = n - k;
  }

  // Slide window leftwards.
  for (int i = n - k - 1; i >= 0; --i) {
    // Remove the rightmost character of current window: s[i + k]
    int val_right = s[i + k] - 'a' + 1;
    long long remove_term = (val_right * p_pow_k1) % m;
    cur_hash = (cur_hash - remove_term + m) % m;

    // Multiply by p (shift all powers up by 1).
    cur_hash = (cur_hash * p) % m;

    // Add new leftmost character: s[i] with power 0.
    int val_left = s[i] - 'a' + 1;
    cur_hash = (cur_hash + val_left) % m;

    if (cur_hash == hashValue) {
      best_start = i;
    }
  }

  return s.substr(best_start, k);
}

}  // namespace

FindSubstringWithGivenHashValueSolution::
    FindSubstringWithGivenHashValueSolution() {
  setMetaInfo({.id = 2156,
               .title = "Find Substring With Given Hash Value",
               .url = "https://leetcode.com/problems/find-substring-with-given-hash-value/"});

  registerStrategy(
      {.name = "Rolling Hash (Right-to-Left)",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Sliding Window", "Rolling Hash", "Hash Function"}},
      subStrHashImpl);
}

std::string FindSubstringWithGivenHashValueSolution::subStrHash(
    const std::string& s, int power, int modulo, int k, int hashValue) {
  return getSolution()(s, power, modulo, k, hashValue);
}

}  // namespace leetcode::problem_2156
