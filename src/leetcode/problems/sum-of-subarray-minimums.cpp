#include "leetcode/problems/sum-of-subarray-minimums.h"

#include <stack>

namespace leetcode::problem_907 {

namespace {

constexpr int kMod = 1000000007;

int sumSubarrayMinsImpl(std::vector<int>& arr) {
  const int n = static_cast<int>(arr.size());
  std::vector<int> left(n), right(n);
  std::stack<int> st;

  // Previous strictly smaller: left[i] = index of previous element < arr[i]
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }
    left[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }

  while (!st.empty()) st.pop();

  // Next element <= arr[i]: right[i] = index of next element <= arr[i]
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && arr[st.top()] > arr[i]) {
      st.pop();
    }
    right[i] = st.empty() ? n : st.top();
    st.push(i);
  }

  long long result = 0;
  for (int i = 0; i < n; ++i) {
    long long ways = (long long)(i - left[i]) * (right[i] - i);
    result = (result + (long long)arr[i] * ways) % kMod;
  }
  return static_cast<int>(result);
}

}  // namespace

SumOfSubarrayMinimumsSolution::SumOfSubarrayMinimumsSolution() {
  setMetaInfo({.id = 907,
               .title = "Sum of Subarray Minimums",
               .url = "https://leetcode.com/problems/sum-of-subarray-minimums/"});
  registerStrategy({.name = "MonotonicStack",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Stack", "Monotonic Stack", "Dynamic Programming"}},
                   sumSubarrayMinsImpl);
}

int SumOfSubarrayMinimumsSolution::sumSubarrayMins(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace leetcode::problem_907
