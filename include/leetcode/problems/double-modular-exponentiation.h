#ifndef LEETCODE_PROBLEMS_DOUBLE_MODULAR_EXPONENTIATION_H__
#define LEETCODE_PROBLEMS_DOUBLE_MODULAR_EXPONENTIATION_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2961 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&, int)>;

class DoubleModularExponentiationSolution
    : public SolutionBase<Func> {
public:
    std::vector<int> getGoodIndices(std::vector<std::vector<int>>& variables,
                                    int target);

    DoubleModularExponentiationSolution();
};

}  // namespace leetcode::problem_2961

#endif  // LEETCODE_PROBLEMS_DOUBLE_MODULAR_EXPONENTIATION_H__
