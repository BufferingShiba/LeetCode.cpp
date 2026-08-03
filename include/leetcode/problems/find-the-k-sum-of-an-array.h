#ifndef LEETCODE_PROBLEMS_FIND_THE_K_SUM_OF_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_THE_K_SUM_OF_AN_ARRAY_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2386 {

using Func = std::function<long long(std::vector<int>&, int)>;

class FindTheKSumOfAnArraySolution : public SolutionBase<Func> {
 public:
  FindTheKSumOfAnArraySolution() {
    setMetaInfo({.id = 2386,
                 .title = "Find the K-Sum of an Array",
                 .url = "https://leetcode.com/problems/find-the-k-sum-of-an-array/"});

    registerStrategy(
        {.name = "heap-subset-sum",
         .expected = "Accepted",
         .time_complexity = "O(n log n + k log k)",
         .space_complexity = "O(k)",
         .tags = {"Array", "Sorting", "Heap"},
         .notes =
             "Transform: base = sum of positives; each subsequence sum = "
             "base minus a subset sum of abs(nums). Sort |nums| and enumerate "
             "the k smallest subset sums via a min-heap."},
        solveKSum);
  }

  long long kSum(std::vector<int>& nums, int k) {
    return getSolution()(nums, k);
  }

 private:
  static long long solveKSum(std::vector<int>& nums, int k);
};

}  // namespace problem_2386
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_K_SUM_OF_AN_ARRAY_H__
