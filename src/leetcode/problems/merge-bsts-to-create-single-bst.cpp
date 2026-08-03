#include "leetcode/problems/merge-bsts-to-create-single-bst.h"

#include <unordered_map>
#include <unordered_set>

namespace leetcode::problem_1932 {

namespace {

long long countNodes(TreeNode* node) {
  if (node == nullptr) return 0;
  return 1 + countNodes(node->left) + countNodes(node->right);
}

bool checkBST(TreeNode* node, long long lower, long long upper) {
  if (node == nullptr) return true;
  if (node->val <= lower || node->val >= upper) return false;
  return checkBST(node->left, lower, node->val) &&
         checkBST(node->right, node->val, upper);
}

// Merge subtrees whose root value equals a leaf value.
void mergeTree(TreeNode*& node, std::unordered_map<int, TreeNode*>& byRoot) {
  if (node == nullptr) return;
  if (node->left == nullptr && node->right == nullptr) {
    auto it = byRoot.find(node->val);
    if (it != byRoot.end() && it->second != nullptr && it->second != node) {
      TreeNode* sub = it->second;
      it->second = nullptr;  // mark used
      delete node;
      node = sub;
      mergeTree(node, byRoot);
    }
    return;
  }
  mergeTree(node->left, byRoot);
  mergeTree(node->right, byRoot);
}

TreeNode* canMergeImpl(std::vector<TreeNode*>& trees) {
  if (trees.empty()) return nullptr;

  std::unordered_map<int, TreeNode*> byRoot;
  std::unordered_map<int, int> appearCnt;
  std::unordered_set<int> allVals;

  for (TreeNode* t : trees) {
    if (t == nullptr) continue;
    byRoot[t->val] = t;
    allVals.insert(t->val);
    if (t->left != nullptr) {
      ++appearCnt[t->left->val];
      allVals.insert(t->left->val);
    }
    if (t->right != nullptr) {
      ++appearCnt[t->right->val];
      allVals.insert(t->right->val);
    }
  }

  // Determine the single final root: its value never appears as a non-root node.
  TreeNode* finalRoot = nullptr;
  for (const auto& [val, root] : byRoot) {
    auto it = appearCnt.find(val);
    bool appearsAsNonRoot = it != appearCnt.end() && it->second > 0;
    if (!appearsAsNonRoot) {
      if (finalRoot != nullptr) return nullptr;  // more than one candidate
      finalRoot = root;
    } else if (it->second != 1) {
      return nullptr;  // root value appears more than once -> cannot merge uniquely
    }
  }
  if (finalRoot == nullptr) return nullptr;

  mergeTree(finalRoot, byRoot);

  // All input trees must be merged (every non-final root is a value appearing at
  // a leaf), and the final tree must contain every distinct value exactly once.
  if (countNodes(finalRoot) != static_cast<long long>(allVals.size())) {
    return nullptr;
  }
  if (!checkBST(finalRoot, LLONG_MIN, LLONG_MAX)) return nullptr;
  return finalRoot;
}

}  // namespace

MergeBstsToCreateSingleBstSolution::MergeBstsToCreateSingleBstSolution() {
  setMetaInfo({.id = 1932,
               .title = "Merge BSTs to Create Single BST",
               .url = "https://leetcode.com/problems/merge-bsts-to-create-single-bst/"});
  registerStrategy(
      {"Hashing+Merge+BSTCheck", "Accepted", "O(N)", "O(N)",
       std::vector<std::string>{"Hash Table", "Tree", "Depth-First Search",
                                "Binary Search Tree"}},
      canMergeImpl);
}

TreeNode* MergeBstsToCreateSingleBstSolution::canMerge(std::vector<TreeNode*>& trees) {
  return getSolution()(trees);
}

}  // namespace leetcode::problem_1932
