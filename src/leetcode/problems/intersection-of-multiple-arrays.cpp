#include "leetcode/problems/intersection-of-multiple-arrays.h"

#include <array>
#include <cstddef>
#include <vector>

namespace leetcode::problem_2248 {
namespace {

std::vector<int> intersectionImpl(std::vector<std::vector<int>>& nums) {
  constexpr int kMaxValue = 1000;
  std::array<int, kMaxValue + 1> count{};
  for (const auto& arr : nums) {
    for (int v : arr) {
      ++count[v];
    }
  }
  std::vector<int> result;
  const std::size_t target = nums.size();
  for (int v = 1; v <= kMaxValue; ++v) {
    if (count[v] == static_cast<int>(target)) {
      result.push_back(v);
    }
  }
  return result;
}

}  // namespace

IntersectionOfMultipleArraysSolution::IntersectionOfMultipleArraysSolution() {
  setMetaInfo(
      {.id = 2248,
       .title = "Intersection of Multiple Arrays",
       .url = "https://leetcode.com/problems/intersection-of-multiple-arrays/"});
  registerStrategy(
      {.name = "HashMapCounting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Sorting", "Counting"}},
      intersectionImpl);
}

std::vector<int> IntersectionOfMultipleArraysSolution::intersection(
    std::vector<std::vector<int>>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2248
