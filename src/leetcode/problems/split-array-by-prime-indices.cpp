#include "leetcode/problems/split-array-by-prime-indices.h"

namespace leetcode {
namespace problem_3618 {

static long long splitArrayImpl(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());

    // Indices 0 and 1 are not prime; if n <= 2, all elements go to B.
    if (n <= 2) {
        long long sum = 0;
        for (int x : nums) sum += x;
        return sum < 0 ? -sum : sum;
    }

    // Sieve of Eratosthenes for indices [0, n-1]
    std::vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    long long sumA = 0, sumB = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime[i]) {
            sumA += nums[i];
        } else {
            sumB += nums[i];
        }
    }

    long long diff = sumA - sumB;
    return diff < 0 ? -diff : diff;
}

SplitArrayByPrimeIndicesSolution::SplitArrayByPrimeIndicesSolution() {
    setMetaInfo({.id = 3618,
                 .title = "Split Array by Prime Indices",
                 .url = "https://leetcode.com/problems/split-array-by-prime-indices/"});
    registerStrategy(
        {.name = "Sieve",
         .expected = "Accepted",
         .time_complexity = "O(n log log n)",
         .space_complexity = "O(n)",
         .tags = {"Array", "Math", "Number Theory"}},
        splitArrayImpl);
    setDefaultStrategy();
}

long long SplitArrayByPrimeIndicesSolution::splitArray(std::vector<int>& nums) {
    return getSolution()(nums);
}

}  // namespace problem_3618
}  // namespace leetcode
