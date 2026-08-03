#include "leetcode/problems/minimum-operations-to-transform-array-into-alternating-prime.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3896 {

static constexpr int MAX_VAL = 200000;

static std::vector<bool> sievePrimes(int limit) {
  std::vector<bool> is_prime(limit + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i * i <= limit; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return is_prime;
}

static int minOperationsImpl(std::vector<int>& nums) {
  static const std::vector<bool> is_prime = sievePrimes(MAX_VAL);

  static const std::vector<int> next_prime = []() {
    std::vector<int> np(MAX_VAL + 1);
    int cur = MAX_VAL + 1;  // sentinel (should never be used)
    for (int i = MAX_VAL; i >= 0; --i) {
      if (is_prime[i]) cur = i;
      np[i] = cur;
    }
    return np;
  }();

  static const std::vector<int> next_non_prime = []() {
    std::vector<int> nnp(MAX_VAL + 1);
    int cur = MAX_VAL + 1;
    for (int i = MAX_VAL; i >= 0; --i) {
      if (!is_prime[i]) cur = i;
      nnp[i] = cur;
    }
    return nnp;
  }();

  long long ops = 0;
  const int n = static_cast<int>(nums.size());
  for (int i = 0; i < n; ++i) {
    int val = nums[i];
    if (i % 2 == 0) {
      // even index: must be prime
      ops += next_prime[val] - val;
    } else {
      // odd index: must be non-prime
      ops += next_non_prime[val] - val;
    }
  }
  return static_cast<int>(ops);
}

MinimumOperationsToTransformArrayIntoAlternatingPrimeSolution::
    MinimumOperationsToTransformArrayIntoAlternatingPrimeSolution() {
  setMetaInfo({.id = 3896,
               .title = "Minimum Operations to Transform Array into Alternating "
                        "Prime",
               .url = "https://leetcode.com/problems/minimum-operations-to-"
                      "transform-array-into-alternating-prime/"});

  registerStrategy(
      {.name = "Sieve + Precomputed Next",
       .expected = "Accepted",
       .time_complexity = "O(MAX log log MAX + N)",
       .space_complexity = "O(MAX)",
       .tags = {"Array", "Math", "Number Theory", "Sieve"}},
      minOperationsImpl);
}

int MinimumOperationsToTransformArrayIntoAlternatingPrimeSolution::minOperations(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3896
}  // namespace leetcode
