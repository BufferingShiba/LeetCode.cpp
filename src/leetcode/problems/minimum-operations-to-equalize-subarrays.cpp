#include "leetcode/problems/minimum-operations-to-equalize-subarrays.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace leetcode::problem_3762 {

static std::vector<long long> minOperationsImpl(std::vector<int>& nums, int k,
                                                std::vector<std::vector<int>>& queries) {
  int n = static_cast<int>(nums.size());

  // remainder and normalized values
  std::vector<int> rem(n);
  std::vector<int> vals(n);
  for (int i = 0; i < n; ++i) {
    rem[i] = nums[i] % k;
    vals[i] = nums[i] / k;
  }

  // next_diff[i] = first index > i with different remainder, or n
  std::vector<int> next_diff(n, n);
  for (int i = n - 2; i >= 0; --i) {
    if (rem[i] == rem[i + 1]) {
      next_diff[i] = next_diff[i + 1];
    } else {
      next_diff[i] = i + 1;
    }
  }

  // coordinate compression for values
  std::vector<int> sorted_vals = vals;
  std::sort(sorted_vals.begin(), sorted_vals.end());
  sorted_vals.erase(std::unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());
  int m = static_cast<int>(sorted_vals.size());

  auto val_to_idx = [&](int v) -> int {
    return static_cast<int>(
        std::lower_bound(sorted_vals.begin(), sorted_vals.end(), v) - sorted_vals.begin());
  };

  // Persistent segment tree
  struct Node {
    int left = -1;
    int right = -1;
    int cnt = 0;
    long long sum = 0;
  };

  std::vector<Node> nodes;
  nodes.reserve(static_cast<size_t>(n + 1) * 20);

  auto new_node = [&]() -> int {
    nodes.push_back({});
    return static_cast<int>(nodes.size()) - 1;
  };

  std::function<int(int, int, int, int, int)> insert =
      [&](int prev_root, int l, int r, int pos, int val) -> int {
    int cur = new_node();
    if (l == r) {
      nodes[cur].cnt = (prev_root >= 0 ? nodes[prev_root].cnt : 0) + 1;
      nodes[cur].sum = (prev_root >= 0 ? nodes[prev_root].sum : 0) + val;
      return cur;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) {
      int new_left =
          insert(prev_root >= 0 ? nodes[prev_root].left : -1, l, mid, pos, val);
      nodes[cur].left = new_left;
      nodes[cur].right = prev_root >= 0 ? nodes[prev_root].right : -1;
    } else {
      nodes[cur].left = prev_root >= 0 ? nodes[prev_root].left : -1;
      int new_right =
          insert(prev_root >= 0 ? nodes[prev_root].right : -1, mid + 1, r, pos, val);
      nodes[cur].right = new_right;
    }
    int lc = nodes[cur].left;
    int rc = nodes[cur].right;
    nodes[cur].cnt = (lc >= 0 ? nodes[lc].cnt : 0) + (rc >= 0 ? nodes[rc].cnt : 0);
    nodes[cur].sum = (lc >= 0 ? nodes[lc].sum : 0) + (rc >= 0 ? nodes[rc].sum : 0);
    return cur;
  };

  int empty_root = new_node();  // node 0, cnt=0,sum=0, children -1
  std::vector<int> roots(n + 1);
  roots[0] = empty_root;
  for (int i = 0; i < n; ++i) {
    int pos = val_to_idx(vals[i]);
    roots[i + 1] = insert(roots[i], 0, m - 1, pos, vals[i]);
  }

  // helper lambdas for safe node access
  auto left_of = [&](int node_id) -> int {
    return node_id >= 0 ? nodes[node_id].left : -1;
  };
  auto right_of = [&](int node_id) -> int {
    return node_id >= 0 ? nodes[node_id].right : -1;
  };
  auto cnt_of = [&](int node_id) -> int {
    return node_id >= 0 ? nodes[node_id].cnt : 0;
  };
  auto sum_of = [&](int node_id) -> long long {
    return node_id >= 0 ? nodes[node_id].sum : 0;
  };

  std::vector<long long> ans;
  ans.reserve(queries.size());

  for (const auto& q : queries) {
    int l = q[0];
    int r = q[1];

    // remainder uniformity check
    if (next_diff[l] <= r) {
      ans.push_back(-1);
      continue;
    }

    int len = r - l + 1;
    if (len == 1) {
      ans.push_back(0);
      continue;
    }

    int kth = (len + 1) / 2;  // 1-indexed lower median

    int node_r = roots[r + 1];
    int node_l = roots[l];

    long long sum_less = 0;
    long long sum_greater = 0;
    int count_less = 0;
    int count_greater = 0;

    int cur_l = 0;
    int cur_r = m - 1;
    int cur_node_r = node_r;
    int cur_node_l = node_l;

    while (cur_l < cur_r) {
      int mid = cur_l + (cur_r - cur_l) / 2;

      int left_r = left_of(cur_node_r);
      int left_l = left_of(cur_node_l);
      int left_cnt = cnt_of(left_r) - cnt_of(left_l);

      if (kth <= left_cnt) {
        // go left: right-subtree elements are greater than median
        int right_r = right_of(cur_node_r);
        int right_l = right_of(cur_node_l);
        count_greater += cnt_of(right_r) - cnt_of(right_l);
        sum_greater += sum_of(right_r) - sum_of(right_l);
        cur_node_r = left_r;
        cur_node_l = left_l;
        cur_r = mid;
      } else {
        // go right: left-subtree elements are less than median
        kth -= left_cnt;
        count_less += cnt_of(left_r) - cnt_of(left_l);
        sum_less += sum_of(left_r) - sum_of(left_l);
        cur_node_r = right_of(cur_node_r);
        cur_node_l = right_of(cur_node_l);
        cur_l = mid + 1;
      }
    }

    // Now cur_l == cur_r is the index of the median value in sorted_vals
    long long median_val = sorted_vals[cur_l];
    long long result = median_val * count_less - sum_less +
                       sum_greater - median_val * count_greater;
    ans.push_back(result);
  }

  return ans;
}

MinimumOperationsToEqualizeSubarraysSolution::MinimumOperationsToEqualizeSubarraysSolution() {
  setMetaInfo({.id = 3762,
               .title = "Minimum Operations to Equalize Subarrays",
               .url = "https://leetcode.com/problems/minimum-operations-to-equalize-subarrays/"});
  registerStrategy(
      {.name = "persistent_segment_tree",
       .expected = "Accepted",
       .time_complexity = "O((n+q) log n)",
       .space_complexity = "O(n log n)",
       .tags = {"Array", "Math", "Binary Search", "Segment Tree", "Sorting"}},
      minOperationsImpl);
}

std::vector<long long> MinimumOperationsToEqualizeSubarraysSolution::minOperations(
    std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries) {
  return getSolution()(nums, k, queries);
}

}  // namespace leetcode::problem_3762
