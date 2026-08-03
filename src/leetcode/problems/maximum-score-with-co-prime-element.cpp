#include "leetcode/problems/maximum-score-with-co-prime-element.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_3953 {

namespace {

constexpr int kMaxV = 100000;

// Compute total number of elements in nums that share a prime factor with v.
// The work is bounded by the largest value that can occur in a candidate.
// SPF makes factorization O(number of distinct prime factors) per candidate,
// avoiding a trial-division pass over the prime table for every v.
std::vector<int> computeTotalBad(const std::vector<int>& nums, int limit) {
  std::vector<int> freq(limit + 1, 0);
  for (int value : nums) {
    ++freq[value];
  }

  // cntMultiple[d] = number of nums divisible by d.
  std::vector<int> cntMultiple(limit + 1, 0);
  for (int d = 1; d <= limit; ++d) {
    for (int multiple = d; multiple <= limit; multiple += d) {
      cntMultiple[d] += freq[multiple];
    }
  }

  // Smallest-prime-factor sieve, used to factor every candidate in O(log A).
  std::vector<int> spf(limit + 1, 0);
  std::vector<int> primes;
  primes.reserve(limit / 10);
  for (int value = 2; value <= limit; ++value) {
    if (spf[value] == 0) {
      spf[value] = value;
      primes.push_back(value);
    }
    for (int prime : primes) {
      if (prime > spf[value] || prime > limit / value) {
        break;
      }
      spf[prime * value] = prime;
    }
  }

  const int n = static_cast<int>(nums.size());
  std::vector<int> totalBad(limit + 1, 0);
  for (int value = 1; value <= limit; ++value) {
    int remaining = value;
    int primeFactors[8]{};
    int factorCount = 0;
    while (remaining > 1) {
      const int prime = spf[remaining];
      primeFactors[factorCount++] = prime;
      while (remaining % prime == 0) {
        remaining /= prime;
      }
    }

    // Inclusion-exclusion over square-free divisors.  The divisor table
    // avoids rebuilding each product from scratch for every subset.
    const int subsetCount = 1 << factorCount;
    int divisors[64]{};
    divisors[0] = 1;
    int coprimes = cntMultiple[1];
    for (int mask = 1; mask < subsetCount; ++mask) {
      const int bit = __builtin_ctz(static_cast<unsigned>(mask));
      const int previous = mask & (mask - 1);
      divisors[mask] = divisors[previous] * primeFactors[bit];
      const int contribution = cntMultiple[divisors[mask]];
      coprimes += (__builtin_popcount(static_cast<unsigned>(mask)) & 1)
                      ? -contribution
                      : contribution;
    }
    totalBad[value] = n - coprimes;
  }
  return totalBad;
}

int maxScoreImpl(std::vector<int>& nums, int maxVal) {
  const int n = static_cast<int>(nums.size());
  const int maxNum = *std::max_element(nums.begin(), nums.end());
  const int limit = std::min(kMaxV, std::max(maxVal, maxNum));

  std::vector<int> freq(limit + 1, 0);
  for (int x : nums) freq[x]++;

  const std::vector<int> totalBad = computeTotalBad(nums, limit);

  long long answer = 0;  // changing one element to 1 always achieves score 0

  // --- Option (b): modify selected element to x <= maxVal ---
  const int candidateLimit = std::min(maxVal, kMaxV);
  for (int x = 1; x <= candidateLimit; ++x) {
    long long bad = totalBad[x];
    long long others = std::max<long long>(0, bad - 1);
    long long score = static_cast<long long>(x) - 1 - others;
    if (score > answer) answer = score;
  }

  // --- Option (a): keep selected element unmodified ---
  // V = original value, can exceed maxVal. Applies if cnt_val[V]>=1.
  // V>1: score_a = V - totalBad(V) + 1  (selected elt itself is "bad")
  // V==1: score = 1
  for (int v = 2; v <= limit; ++v) {
    if (freq[v] >= 1) {
      long long score = static_cast<long long>(v) - totalBad[v] + 1;
      if (score > answer) answer = score;
    }
  }
  if (freq[1] >= 1) {
    answer = std::max(answer, 1LL);
  }

  return static_cast<int>(answer);
}

}  // namespace

MaximumScoreWithCoPrimeElementSolution::MaximumScoreWithCoPrimeElementSolution() {
  setMetaInfo({.id = 3953,
               .title = "Maximum Score with Co-Prime Element",
               .url = "https://leetcode.com/problems/maximum-score-with-co-prime-element/"});
  registerStrategy(
      {.name = "MobiusInclusionExclusion",
       .expected = "Accepted",
       .time_complexity = "O(n + K log K)",
       .space_complexity = "O(K)",
       .tags = {"Array", "Hash Table", "Math", "Number Theory",
                "Enumeration"}},
      maxScoreImpl);
}

int MaximumScoreWithCoPrimeElementSolution::maxScore(std::vector<int>& nums,
                                                     int maxVal) {
  return getSolution()(nums, maxVal);
}

}  // namespace problem_3953
}  // namespace leetcode
