#ifndef LEETCODE_PROBLEMS_TRIANGLE_H
#define LEETCODE_PROBLEMS_TRIANGLE_H

#include "leetcode/core.h"

namespace leetcode::problem_120 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class TriangleSolution : public SolutionBase<Func> {
public:
    TriangleSolution();
    int minimumTotal(std::vector<std::vector<int>>& triangle);
};

} // namespace leetcode::problem_120

#endif // LEETCODE_PROBLEMS_TRIANGLE_H
