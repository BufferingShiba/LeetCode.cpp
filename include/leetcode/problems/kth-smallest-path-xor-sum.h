#ifndef LEETCODE_PROBLEMS_KTH_SMALLEST_PATH_XOR_SUM_H
#define LEETCODE_PROBLEMS_KTH_SMALLEST_PATH_XOR_SUM_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3590 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&, std::vector<std::vector<int>>&)>;

class KthSmallestPathXorSumSolution : public SolutionBase<Func> {
public:
    KthSmallestPathXorSumSolution();

    std::vector<int> kthSmallest(std::vector<int>& par, std::vector<int>& vals, std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_3590

#endif  // LEETCODE_PROBLEMS_KTH_SMALLEST_PATH_XOR_SUM_H
