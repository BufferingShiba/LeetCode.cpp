#include "leetcode/problems/the-k-strongest-values-in-an-array.h"

#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_1471 {
namespace {

std::vector<int> getStrongestImpl(std::vector<int>& arr, int k) {
  std::sort(arr.begin(), arr.end());
  const int n = static_cast<int>(arr.size());
  const int m = arr[(n - 1) / 2];
  int left = 0;
  int right = n - 1;
  std::vector<int> result;
  result.reserve(k);
  for (int i = 0; i < k; ++i) {
    if (std::abs(arr[left] - m) > std::abs(arr[right] - m)) {
      result.push_back(arr[left++]);
    } else {
      result.push_back(arr[right--]);
    }
  }
  return result;
}

}  // namespace

TheKStrongestValuesInAnArraySolution::TheKStrongestValuesInAnArraySolution() {
  setMetaInfo({.id = 1471,
               .title = "The k Strongest Values in an Array",
               .url = "https://leetcode.com/problems/the-k-strongest-values-in-an-array/"});
  registerStrategy(
      {.name = "sort_and_two_pointers",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Sorting"}},
      getStrongestImpl);
}

std::vector<int> TheKStrongestValuesInAnArraySolution::getStrongest(
    std::vector<int>& arr, int k) {
  return getSolution()(arr, k);
}

}  // namespace problem_1471
}  // namespace leetcode
