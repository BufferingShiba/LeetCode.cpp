#ifndef LEETCODE_PROBLEMS_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H__
#define LEETCODE_PROBLEMS_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_108 {

using Func = std::function<leetcode::TreeNode*(std::vector<int>&)>;

class ConvertSortedArrayToBinarySearchTreeSolution
    : public SolutionBase<Func> {
 public:
  ConvertSortedArrayToBinarySearchTreeSolution() {
    setMetaInfo({.id = 108,
                 .title = "Convert Sorted Array to Binary Search Tree",
                 .url =
                     "https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/"});

    registerStrategy(
        {.name = "DivideAndConquer",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(log n)",
         .tags = {"Array", "Divide and Conquer", "Tree", "Binary Search Tree",
                  "Binary Tree"}},
        sortedArrayToBSTImpl);
  }

  leetcode::TreeNode* sortedArrayToBST(std::vector<int>& nums);

 private:
  static leetcode::TreeNode* sortedArrayToBSTImpl(std::vector<int>& nums);
};

}  // namespace leetcode::problem_108

#endif  // LEETCODE_PROBLEMS_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H__
