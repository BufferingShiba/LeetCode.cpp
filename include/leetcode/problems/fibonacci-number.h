#ifndef LEETCODE_PROBLEMS_FIBONACCI_NUMBER_H__
#define LEETCODE_PROBLEMS_FIBONACCI_NUMBER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_509 {

using Func = std::function<int(int)>;

class FibonacciNumberSolution : public SolutionBase<Func> {
 public:
  FibonacciNumberSolution();

  int fib(int n);
};

}  // namespace problem_509
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIBONACCI_NUMBER_H__
