#include "leetcode/problems/most-frequent-subtree-sum.h"

#include <unordered_map>

namespace leetcode::problem_508 {

namespace {

int dfs(TreeNode* node, std::unordered_map<int, int>& freq, int& max_freq) {
  if (!node) return 0;
  int sum = node->val + dfs(node->left, freq, max_freq) +
            dfs(node->right, freq, max_freq);
  int f = ++freq[sum];
  if (f > max_freq) max_freq = f;
  return sum;
}

std::vector<int> findFrequentTreeSumImpl(TreeNode* root) {
  std::unordered_map<int, int> freq;
  int max_freq = 0;
  dfs(root, freq, max_freq);

  std::vector<int> result;
  for (const auto& [sum, f] : freq) {
    if (f == max_freq) result.push_back(sum);
  }
  return result;
}

}  // namespace

MostFrequentSubtreeSumSolution::MostFrequentSubtreeSumSolution() {
  setMetaInfo({.id = 508,
               .title = "Most Frequent Subtree Sum",
               .url = "https://leetcode.com/problems/most-frequent-subtree-sum/"});
  registerStrategy(
      {.name = "DFS Postorder + Hash Map",
       .expected = "Accepted",
       .time_complexity = "O(N)",
       .space_complexity = "O(N)",
       .tags = {"Hash Table", "Tree", "Depth-First Search", "Binary Tree"}},
      findFrequentTreeSumImpl);
}

std::vector<int> MostFrequentSubtreeSumSolution::findFrequentTreeSum(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace leetcode::problem_508
