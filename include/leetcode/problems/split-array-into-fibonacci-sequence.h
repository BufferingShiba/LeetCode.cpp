#ifndef LEETCODE_PROBLEMS_SPLIT_ARRAY_INTO_FIBONACCI_SEQUENCE_H__
#define LEETCODE_PROBLEMS_SPLIT_ARRAY_INTO_FIBONACCI_SEQUENCE_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_842 {

using Func = std::function<std::vector<int>(std::string)>;

class SplitArrayIntoFibonacciSequenceSolution
    : public SolutionBase<Func> {
 public:
  SplitArrayIntoFibonacciSequenceSolution();

  std::vector<int> splitIntoFibonacci(std::string num);
};

}  // namespace problem_842
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPLIT_ARRAY_INTO_FIBONACCI_SEQUENCE_H__
