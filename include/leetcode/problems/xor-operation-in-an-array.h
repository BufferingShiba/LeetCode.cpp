#ifndef LEETCODE_PROBLEMS_XOR_OPERATION_IN_AN_ARRAY_H
#define LEETCODE_PROBLEMS_XOR_OPERATION_IN_AN_ARRAY_H

#include "leetcode/core.h"

namespace leetcode::problem_1486 {

int xorOperation(int n, int start);

class XorOperationInAnArraySolution
    : public SolutionBase<std::function<int(int, int)>> {
 public:
  XorOperationInAnArraySolution();
};

}  // namespace leetcode::problem_1486

#endif  // LEETCODE_PROBLEMS_XOR_OPERATION_IN_AN_ARRAY_H
