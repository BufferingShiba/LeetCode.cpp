#ifndef LEETCODE_PROBLEMS_RELATIVE_RANKS_H__
#define LEETCODE_PROBLEMS_RELATIVE_RANKS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_506 {

using Func = std::function<std::vector<std::string>(std::vector<int>&)>;

class RelativeRanksSolution : public SolutionBase<Func> {
public:
    RelativeRanksSolution();

    std::vector<std::string> findRelativeRanks(std::vector<int>& score);
};

}  // namespace leetcode::problem_506

#endif  // LEETCODE_PROBLEMS_RELATIVE_RANKS_H__
