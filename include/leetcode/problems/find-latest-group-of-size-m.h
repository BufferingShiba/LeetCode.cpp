#ifndef LEETCODE_PROBLEMS_FIND_LATEST_GROUP_OF_SIZE_M_H__
#define LEETCODE_PROBLEMS_FIND_LATEST_GROUP_OF_SIZE_M_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1562 {

using Func = std::function<int(std::vector<int>&, int)>;

class FindLatestGroupOfSizeMSolution : public SolutionBase<Func> {
public:
    FindLatestGroupOfSizeMSolution();

    int findLatestStep(std::vector<int>& arr, int m);
};

}  // namespace leetcode::problem_1562

#endif  // LEETCODE_PROBLEMS_FIND_LATEST_GROUP_OF_SIZE_M_H__
