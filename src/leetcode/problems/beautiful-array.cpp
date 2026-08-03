#include "leetcode/problems/beautiful-array.h"

#include <vector>

namespace leetcode {
namespace problem_932 {
namespace {

//! Divide-and-conquer construction.
//! Key invariant: 2*nums[k] == nums[i] + nums[j] requires the sum to be even.
//! If we place all odds on the left and all evens on the right, then any
//! cross-half pair (i in left, j in right) has odd sum, which can never equal
//! 2*x (even). Recursively, each side must itself be beautiful.
//! left  (odds):  f((n+1)/2) mapped as 2*x-1
//! right (evens): f(n/2)      mapped as 2*x
std::vector<int> build(int n) {
  if (n == 1) {
    return {1};
  }
  std::vector<int> left = build((n + 1) / 2);
  std::vector<int> right = build(n / 2);
  std::vector<int> result;
  result.reserve(n);
  for (int x : left) {
    result.push_back(2 * x - 1);
  }
  for (int x : right) {
    result.push_back(2 * x);
  }
  return result;
}

std::vector<int> beautifulArrayImpl(int n) { return build(n); }

}  // namespace

BeautifulArraySolution::BeautifulArraySolution() {
  setMetaInfo({.id = 932,
               .title = "Beautiful Array",
               .url = "https://leetcode.com/problems/beautiful-array/"});
  registerStrategy(
      {.name = "DivideAndConquer",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n log n)",
       .tags = {"Array", "Math", "Divide and Conquer"}},
      beautifulArrayImpl);
}

std::vector<int> BeautifulArraySolution::beautifulArray(int n) {
  return getSolution()(n);
}

}  // namespace problem_932
}  // namespace leetcode
