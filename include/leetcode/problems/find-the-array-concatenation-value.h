#ifndef LEETCODE_PROBLEMS_FIND_THE_ARRAY_CONCATENATION_VALUE_H__
#define LEETCODE_PROBLEMS_FIND_THE_ARRAY_CONCATENATION_VALUE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2562 {

using Func = std::function<long long(std::vector<int>&)>;

class FindTheArrayConcatenationValueSolution
    : public SolutionBase<Func> {
 public:
  FindTheArrayConcatenationValueSolution();

  long long findTheArrayConcVal(std::vector<int>& nums);
};

}  // namespace problem_2562
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_ARRAY_CONCATENATION_VALUE_H__
