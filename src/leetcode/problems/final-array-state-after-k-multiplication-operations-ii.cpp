#include "leetcode/problems/final-array-state-after-k-multiplication-operations-ii.h"

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

namespace {

constexpr int kMod = 1'000'000'007;

long long ModPow(long long base, long long exp) {
  long long result = 1;
  base %= kMod;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % kMod;
    base = (base * base) % kMod;
    exp >>= 1;
  }
  return result;
}

std::vector<int> getFinalStateImpl(std::vector<int>& nums, int k, int multiplier) {
  if (multiplier == 1) {
    std::vector<int> result(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      result[i] = nums[i] % kMod;
    }
    return result;
  }

  int n = static_cast<int>(nums.size());

  // Min-heap: (value, index)
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<std::pair<long long, int>>>
      pq;

  long long max_val = 0;
  for (int i = 0; i < n; ++i) {
    pq.emplace(nums[i], i);
    if (nums[i] > max_val) max_val = nums[i];
  }

  // Simulate until k runs out or min * multiplier > max
  while (k > 0) {
    auto [val, idx] = pq.top();
    if (val * multiplier > max_val) {
      break;
    }
    pq.pop();
    val *= multiplier;
    if (val > max_val) max_val = val;
    pq.emplace(val, idx);
    --k;
  }

  // Extract all elements from heap (sorted by value, then index)
  std::vector<std::pair<long long, int>> arr;
  arr.reserve(n);
  while (!pq.empty()) {
    arr.push_back(pq.top());
    pq.pop();
  }

  std::vector<int> result(n);

  if (k == 0) {
    for (auto& [val, idx] : arr) {
      result[idx] = static_cast<int>(val % kMod);
    }
  } else {
    int cycles = k / n;
    int remainder = k % n;

    long long pow_all = ModPow(multiplier, cycles);
    long long pow_extra = ModPow(multiplier, cycles + 1);

    for (int i = 0; i < n; ++i) {
      long long val = arr[i].first % kMod;
      if (i < remainder) {
        val = (val * pow_extra) % kMod;
      } else {
        val = (val * pow_all) % kMod;
      }
      result[arr[i].second] = static_cast<int>(val);
    }
  }

  return result;
}

}  // namespace

namespace leetcode {
namespace problem_3266 {

FinalArrayStateAfterKMultiplicationOperationsIiSolution::
    FinalArrayStateAfterKMultiplicationOperationsIiSolution() {
  setMetaInfo({.id = 3266,
               .title = "Final Array State After K Multiplication Operations II",
               .url = "https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/"});
  registerStrategy(
      {.name = "HeapSimulation",
       .expected = "Accepted",
       .time_complexity = "O(n log n + min(k, n log M) log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Heap (Priority Queue)", "Simulation", "Math"}},
      getFinalStateImpl);
}

std::vector<int> FinalArrayStateAfterKMultiplicationOperationsIiSolution::getFinalState(
    std::vector<int>& nums, int k, int multiplier) {
  return getSolution()(nums, k, multiplier);
}

}  // namespace problem_3266
}  // namespace leetcode
