#ifndef LEETCODE_PROBLEM_373_H
#define LEETCODE_PROBLEM_373_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_373 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<int>&, std::vector<int>&, int)>;

class FindKPairsWithSmallestSumsSolution : public SolutionBase<Func> {
public:
    FindKPairsWithSmallestSumsSolution();

    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k);
};

} // namespace problem_373
} // namespace leetcode

#endif
