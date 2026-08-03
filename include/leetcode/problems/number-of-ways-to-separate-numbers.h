#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SEPARATE_NUMBERS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SEPARATE_NUMBERS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1977 {

using Func = std::function<int(std::string)>;

class NumberOfWaysToSeparateNumbersSolution
    : public SolutionBase<Func> {
 public:
  int numberOfCombinations(std::string num);

  NumberOfWaysToSeparateNumbersSolution();
};

}  // namespace problem_1977
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SEPARATE_NUMBERS_H__
