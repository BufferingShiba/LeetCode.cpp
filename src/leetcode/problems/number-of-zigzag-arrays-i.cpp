#include "leetcode/problems/number-of-zigzag-arrays-i.h"

#include <vector>

namespace leetcode::problem_3699 {
namespace {

constexpr long long kMod = 1000000007LL;

int zigZagArraysImpl(int n, int l, int r) {
  const int m = r - l + 1;
  // up[i]   : count of valid arrays ending with value (l+i) and last step increasing
  // down[i] : count of valid arrays ending with value (l+i) and last step decreasing
  std::vector<long long> up(m), down(m);

  // Base case: length 2.
  // up[v] = number of pairs (w, v) with w < v = v - l.
  // down[v] = number of pairs (v, w) with w > v = r - v.
  for (int v = l; v <= r; ++v) {
    int idx = v - l;
    up[idx] = v - l;
    down[idx] = r - v;
  }

  if (n <= 2) {
    long long ans = 0;
    for (int i = 0; i < m; ++i) ans = (ans + up[i] + down[i]) % kMod;
    return static_cast<int>(ans);
  }

  for (int pos = 3; pos <= n; ++pos) {
    std::vector<long long> newUp(m), newDown(m);
    // newUp[v] = sum_{w < v} down[w]   (prefix sum)
    long long running = 0;
    for (int i = 0; i < m; ++i) {
      newUp[i] = running;
      running = (running + down[i]) % kMod;
    }
    // newDown[v] = sum_{w > v} up[w]   (suffix sum)
    running = 0;
    for (int i = m - 1; i >= 0; --i) {
      newDown[i] = running;
      running = (running + up[i]) % kMod;
    }
    up.swap(newUp);
    down.swap(newDown);
  }

  long long ans = 0;
  for (int i = 0; i < m; ++i) ans = (ans + up[i] + down[i]) % kMod;
  return static_cast<int>(ans);
}

}  // namespace

NumberOfZigzagArraysISolution::NumberOfZigzagArraysISolution() {
  setMetaInfo({3699, "Number of ZigZag Arrays I",
               "https://leetcode.com/problems/number-of-zigzag-arrays-i/"});
  registerStrategy(
      {"prefix-sum-dp", "Accepted", "O(n*m)", "O(m)", {"Dynamic Programming", "Prefix Sum"}},
      zigZagArraysImpl);
}

int NumberOfZigzagArraysISolution::zigZagArrays(int n, int l, int r) {
  return getSolution()(n, l, r);
}

}  // namespace leetcode::problem_3699
