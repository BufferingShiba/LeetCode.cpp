#ifndef LEETCODE_PROBLEMS_COUNT_SQUARE_SUM_TRIPLES_H__
#define LEETCODE_PROBLEMS_COUNT_SQUARE_SUM_TRIPLES_H__

#include "leetcode/core.h"

namespace leetcode::problem_1925 {

using Func = std::function<int(int)>;

class CountSquareSumTriplesSolution : public SolutionBase<Func> {
 public:
  CountSquareSumTriplesSolution();
  int countTriples(int n);
};

}  // namespace leetcode::problem_1925

#endif  // LEETCODE_PROBLEMS_COUNT_SQUARE_SUM_TRIPLES_H__
