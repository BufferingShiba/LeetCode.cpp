#ifndef LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_A_STRING_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_A_STRING_IN_AN_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2496 {

using Func = std::function<int(std::vector<std::string>&)>;

class MaximumValueOfAStringInAnArraySolution
    : public SolutionBase<Func> {
 public:
  MaximumValueOfAStringInAnArraySolution();

  int maximumValue(std::vector<std::string>& strs);
};

}  // namespace problem_2496
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_A_STRING_IN_AN_ARRAY_H__
