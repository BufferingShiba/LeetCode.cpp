#ifndef LEETCODE_PROBLEMS_LARGEST_EVEN_NUMBER_H__
#define LEETCODE_PROBLEMS_LARGEST_EVEN_NUMBER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3798 {

using Func = std::function<std::string(std::string)>;

class LargestEvenNumberSolution : public SolutionBase<Func> {
 public:
  LargestEvenNumberSolution();

  std::string largestEven(std::string s);
};

}  // namespace problem_3798
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_EVEN_NUMBER_H__
