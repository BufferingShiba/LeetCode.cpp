#ifndef LEETCODE_PROBLEMS_COUNT_VOWELS_PERMUTATION_H__
#define LEETCODE_PROBLEMS_COUNT_VOWELS_PERMUTATION_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1220 {

using Func = std::function<int(int n)>;

class CountVowelsPermutationSolution : public SolutionBase<Func> {
 public:
  CountVowelsPermutationSolution();

  int countVowelPermutation(int n) { return getSolution()(n); }
};

}  // namespace leetcode::problem_1220

#endif  // LEETCODE_PROBLEMS_COUNT_VOWELS_PERMUTATION_H__
