#include "leetcode/problems/sum-of-largest-prime-substrings.h"

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_3556 {

namespace {

bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}

long long sumOfLargestPrimesImpl(std::string s) {
  int n = static_cast<int>(s.size());
  std::unordered_set<long long> unique_nums;

  // Enumerate all substrings, convert to integer, skip leading zeros implicitly
  for (int i = 0; i < n; ++i) {
    long long val = 0;
    for (int j = i; j < n; ++j) {
      val = val * 10 + (s[j] - '0');
      unique_nums.insert(val);
    }
  }

  // Collect primes
  std::vector<long long> primes;
  for (long long num : unique_nums) {
    if (isPrime(num)) {
      primes.push_back(num);
    }
  }

  // Sort descending
  std::sort(primes.begin(), primes.end(), std::greater<long long>());

  // Sum top 3 (or all if fewer)
  long long sum = 0;
  int count = std::min<int>(3, static_cast<int>(primes.size()));
  for (int i = 0; i < count; ++i) {
    sum += primes[i];
  }
  return sum;
}

}  // namespace

SumOfLargestPrimeSubstringsSolution::SumOfLargestPrimeSubstringsSolution() {
  setMetaInfo({.id = 3556,
               .title = "Sum of Largest Prime Substrings",
               .url = "https://leetcode.com/problems/sum-of-largest-prime-substrings/"});
  registerStrategy({.name = "BruteForce",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2 * sqrt(M))",
                    .space_complexity = "O(n^2)",
                    .tags = {"Hash Table", "Math", "String", "Sorting", "Number Theory"}},
                   sumOfLargestPrimesImpl);
}

long long SumOfLargestPrimeSubstringsSolution::sumOfLargestPrimes(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_3556
}  // namespace leetcode
