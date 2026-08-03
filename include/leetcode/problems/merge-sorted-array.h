#ifndef LEETCODE_PROBLEMS_MERGE_SORTED_ARRAY_H__
#define LEETCODE_PROBLEMS_MERGE_SORTED_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_88 {

using MergeFunc = std::function<void(std::vector<int>&, int, std::vector<int>&, int)>;

class MergeSortedArraySolution : public SolutionBase<MergeFunc> {
 public:
  MergeSortedArraySolution();

  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
};

}  // namespace leetcode::problem_88

#endif  // LEETCODE_PROBLEMS_MERGE_SORTED_ARRAY_H__
