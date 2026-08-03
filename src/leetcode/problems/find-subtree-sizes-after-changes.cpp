#include "leetcode/problems/find-subtree-sizes-after-changes.h"

#include <stack>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3331 {

static std::vector<int> findSubtreeSizesImpl(std::vector<int>& parent,
                                              std::string s) {
  int n = static_cast<int>(parent.size());

  // 1. Build original children adjacency
  std::vector<std::vector<int>> children(n);
  for (int i = 1; i < n; ++i) {
    children[parent[i]].push_back(i);
  }

  // 2. Iterative DFS on original tree to find new parents
  std::vector<int> new_parent(n, -1);
  std::vector<int> last(26, -1);
  std::vector<int> saved_last(n, -1);

  // stack: (node, state)  state=0 enter, state=1 exit
  std::stack<std::pair<int, int>> st;
  st.push({0, 0});

  while (!st.empty()) {
    auto [node, state] = st.top();
    st.pop();

    if (state == 0) {
      // entering node
      int c = s[node] - 'a';
      if (node == 0) {
        new_parent[node] = -1;
      } else {
        new_parent[node] = (last[c] != -1) ? last[c] : parent[node];
      }

      // schedule exit
      st.push({node, 1});
      // schedule children in reverse order (preserves original order)
      for (int i = static_cast<int>(children[node].size()) - 1; i >= 0; --i) {
        st.push({children[node][i], 0});
      }

      // update last occurrence
      saved_last[node] = last[c];
      last[c] = node;
    } else {
      // exiting node – restore last
      int c = s[node] - 'a';
      last[c] = saved_last[node];
    }
  }

  // 3. Build new tree children
  std::vector<std::vector<int>> new_children(n);
  for (int i = 1; i < n; ++i) {
    new_children[new_parent[i]].push_back(i);
  }

  // 4. Iterative post-order to compute subtree sizes
  std::vector<int> ans(n, 1);
  std::stack<std::pair<int, int>> st2;  // (node, state)
  st2.push({0, 0});

  while (!st2.empty()) {
    auto [node, state] = st2.top();
    st2.pop();
    if (state == 0) {
      st2.push({node, 1});
      for (int i = static_cast<int>(new_children[node].size()) - 1; i >= 0;
           --i) {
        st2.push({new_children[node][i], 0});
      }
    } else {
      for (int child : new_children[node]) {
        ans[node] += ans[child];
      }
    }
  }

  return ans;
}

FindSubtreeSizesAfterChangesSolution::FindSubtreeSizesAfterChangesSolution() {
  setMetaInfo({.id = 3331,
               .title = "Find Subtree Sizes After Changes",
               .url =
               "https://leetcode.com/problems/find-subtree-sizes-after-changes/"});
  registerStrategy(
      {.name = "DFS with last occurrence",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "String", "Tree",
                "Depth-First Search"}},
      findSubtreeSizesImpl);
}

std::vector<int> FindSubtreeSizesAfterChangesSolution::findSubtreeSizes(
    std::vector<int>& parent, std::string s) {
  return getSolution()(parent, s);
}

}  // namespace problem_3331
}  // namespace leetcode
