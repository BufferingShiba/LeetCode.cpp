#ifndef LEETCODE_PROBLEMS_CONVERT_TO_BASE_2_H_
#define LEETCODE_PROBLEMS_CONVERT_TO_BASE_2_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1017 {

using Func = std::function<std::string(int)>;

class ConvertToBase2Solution : public SolutionBase<Func> {
 public:
  ConvertToBase2Solution();

  std::string baseNeg2(int n) {
    return getSolution()(n);
  }
};

}  // namespace problem_1017
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONVERT_TO_BASE_2_H_
