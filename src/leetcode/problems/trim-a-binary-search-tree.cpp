#include "leetcode/problems/trim-a-binary-search-tree.h"

namespace leetcode::problem_669 {

static TreeNode* trimBSTImpl(TreeNode* root, int low, int high) {
    if (!root) return nullptr;
    if (root->val < low) {
        return trimBSTImpl(root->right, low, high);
    }
    if (root->val > high) {
        return trimBSTImpl(root->left, low, high);
    }
    root->left = trimBSTImpl(root->left, low, high);
    root->right = trimBSTImpl(root->right, low, high);
    return root;
}

TrimABinarySearchTreeSolution::TrimABinarySearchTreeSolution() {
    setMetaInfo({.id = 669, .title = "Trim a Binary Search Tree", .url = "https://leetcode.com/problems/trim-a-binary-search-tree/"});
    registerStrategy({
        .name = "Recursive",
        .expected = "Accepted",
        .time_complexity = "O(n)",
        .space_complexity = "O(h)",
        .tags = {"Tree", "Depth-First Search", "Binary Search Tree", "Binary Tree", "Recursion"}
    }, trimBSTImpl);
    setDefaultStrategy();
}

TreeNode* TrimABinarySearchTreeSolution::trimBST(TreeNode* root, int low, int high) {
    return getSolution()(root, low, high);
}

}  // namespace leetcode::problem_669
