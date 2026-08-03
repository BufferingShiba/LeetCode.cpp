#ifndef LEETCODE_PROBLEMS_REMOVE_ZEROS_IN_DECIMAL_REPRESENTATION_H__
#define LEETCODE_PROBLEMS_REMOVE_ZEROS_IN_DECIMAL_REPRESENTATION_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3726 {

using Func = std::function<long long(long long)>;

class RemoveZerosInDecimalRepresentationSolution
    : public SolutionBase<Func> {
 public:
  RemoveZerosInDecimalRepresentationSolution();

  long long removeZeros(long long n);
};

}  // namespace problem_3726
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_ZEROS_IN_DECIMAL_REPRESENTATION_H__
