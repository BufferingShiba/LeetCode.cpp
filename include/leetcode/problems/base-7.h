#ifndef LEETCODE_PROBLEMS_BASE_7_H_
#define LEETCODE_PROBLEMS_BASE_7_H_

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_504 {

using Func = std::function<std::string(int)>;

class Base7Solution : public SolutionBase<Func> {
 public:
  Base7Solution();
  std::string convertToBase7(int num);
};

}  // namespace problem_504
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BASE_7_H_
