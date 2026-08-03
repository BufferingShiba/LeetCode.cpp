#include "leetcode/problems/maximum-subarray-with-equal-products.h"

#include <algorithm>
#include <map>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3411 {

namespace {

std::vector<std::pair<int, int>> factorize(int value) {
  std::vector<std::pair<int, int>> factors;
  for (int divisor = 2; 1LL * divisor * divisor <= value; ++divisor) {
    if (value % divisor != 0) {
      continue;
    }
    int exponent = 0;
    while (value % divisor == 0) {
      value /= divisor;
      ++exponent;
    }
    factors.emplace_back(divisor, exponent);
  }
  if (value > 1) {
    factors.emplace_back(value, 1);
  }
  return factors;
}

int maxLengthImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int best = 0;
  for (int i = 0; i < n; ++i) {
    std::map<int, int> sum_exponents;
    std::map<int, int> min_exponents;
    std::map<int, int> max_exponents;
    int length = 0;
    for (int j = i; j < n; ++j) {
      ++length;
      const auto factors = factorize(nums[j]);
      std::map<int, int> current_exponents;
      for (const auto& [prime, exponent] : factors) {
        current_exponents[prime] = exponent;
      }
      for (auto& [prime, minimum] : min_exponents) {
        if (!current_exponents.contains(prime)) {
          minimum = 0;
        }
      }

      for (const auto& [prime, exponent] : factors) {
        if (!sum_exponents.contains(prime)) {
          sum_exponents[prime] = exponent;
          min_exponents[prime] = length == 1 ? exponent : 0;
          max_exponents[prime] = exponent;
        } else {
          sum_exponents[prime] += exponent;
          min_exponents[prime] = std::min(min_exponents[prime], exponent);
          max_exponents[prime] = std::max(max_exponents[prime], exponent);
        }
      }

      bool equal_products = true;
      for (const auto& [prime, sum] : sum_exponents) {
        if (sum != max_exponents[prime] + min_exponents[prime]) {
          equal_products = false;
          break;
        }
      }
      if (equal_products) {
        if (j - i + 1 > best) best = j - i + 1;
      }
    }
  }
  return best;
}

}  // namespace

MaximumSubarrayWithEqualProductsSolution::MaximumSubarrayWithEqualProductsSolution() {
  setMetaInfo({.id = 3411,
               .title = "Maximum Subarray With Equal Products",
               .url = "https://leetcode.com/problems/maximum-subarray-with-equal-products/"});
  registerStrategy({.name = "Enumeration",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math", "Enumeration"}},
                   maxLengthImpl);
}

int MaximumSubarrayWithEqualProductsSolution::maxLength(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3411
}  // namespace leetcode
