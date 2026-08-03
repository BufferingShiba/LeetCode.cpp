#include "leetcode/problems/count-anagrams.h"

#include <sstream>
#include <vector>

namespace leetcode {
namespace problem_2514 {
namespace {

constexpr long long kMod = 1000000007LL;

long long modPow(long long base, long long exp, long long mod) {
  long long result = 1;
  base %= mod;
  while (exp > 0) {
    if (exp & 1) result = result * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }
  return result;
}

int countAnagramsImpl(const std::string& s) {
  const int n = static_cast<int>(s.size());

  // Precompute factorials up to n.
  std::vector<long long> fact(n + 1, 1);
  for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % kMod;

  // Precompute inverse factorials.
  std::vector<long long> invFact(n + 1, 1);
  invFact[n] = modPow(fact[n], kMod - 2, kMod);
  for (int i = n; i > 0; --i) invFact[i - 1] = invFact[i] * i % kMod;

  long long answer = 1;
  std::vector<int> freq(26, 0);

  std::istringstream iss(s);
  std::string word;
  while (iss >> word) {
    const int len = static_cast<int>(word.size());
    std::fill(freq.begin(), freq.end(), 0);
    for (char ch : word) {
      ++freq[ch - 'a'];
    }
    long long ways = fact[len];
    for (int f : freq) {
      if (f > 1) ways = ways * invFact[f] % kMod;
    }
    answer = answer * ways % kMod;
  }

  return static_cast<int>(answer);
}

}  // namespace

CountAnagramsSolution::CountAnagramsSolution() {
  setMetaInfo({.id = 2514,
               .title = "Count Anagrams",
               .url = "https://leetcode.com/problems/count-anagrams/"});
  registerStrategy(
      {.name = "combinatorics",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Math", "String", "Combinatorics", "Counting"}},
      countAnagramsImpl);
}

int CountAnagramsSolution::countAnagrams(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_2514
}  // namespace leetcode
