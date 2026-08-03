#ifndef LEETCODE_PROBLEMS_ADDING_TWO_NEGABINARY_NUMBERS_H__
#define LEETCODE_PROBLEMS_ADDING_TWO_NEGABINARY_NUMBERS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1073 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class AddingTwoNegabinaryNumbersSolution
    : public SolutionBase<Func> {
 public:
  AddingTwoNegabinaryNumbersSolution();

  std::vector<int> addNegabinary(std::vector<int>& arr1,
                                 std::vector<int>& arr2);
};

}  // namespace problem_1073
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ADDING_TWO_NEGABINARY_NUMBERS_H__
