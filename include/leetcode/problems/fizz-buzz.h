#ifndef LEETCODE_PROBLEMS_FIZZ_BUZZ_H_
#define LEETCODE_PROBLEMS_FIZZ_BUZZ_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_412 {

using Func = std::function<std::vector<std::string>(int)>;

class FizzBuzzSolution : public SolutionBase<Func> {
 public:
  FizzBuzzSolution();

  std::vector<std::string> fizzBuzz(int n);
};

}  // namespace problem_412
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIZZ_BUZZ_H_
