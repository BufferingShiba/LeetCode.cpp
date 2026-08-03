#ifndef LEETCODE_PROBLEMS_AVERAGE_VALUE_OF_EVEN_NUMBERS_THAT_ARE_DIVISIBLE_BY_THREE_H
#define LEETCODE_PROBLEMS_AVERAGE_VALUE_OF_EVEN_NUMBERS_THAT_ARE_DIVISIBLE_BY_THREE_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2455 {

using Func = std::function<int(std::vector<int>&)>;

class AverageValueOfEvenNumbersThatAreDivisibleByThreeSolution
    : public SolutionBase<Func> {
 public:
  int averageValue(std::vector<int>& nums);

  AverageValueOfEvenNumbersThatAreDivisibleByThreeSolution();
};

}  // namespace problem_2455
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_AVERAGE_VALUE_OF_EVEN_NUMBERS_THAT_ARE_DIVISIBLE_BY_THREE_H
