#ifndef LEETCODE_PROBLEMS_LONG_PRESSED_NAME_H__
#define LEETCODE_PROBLEMS_LONG_PRESSED_NAME_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_925 {

using Func = std::function<bool(std::string, std::string)>;

class LongPressedNameSolution : public SolutionBase<Func> {
 public:
  bool isLongPressedName(std::string name, std::string typed);
  LongPressedNameSolution();
};

}  // namespace problem_925
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONG_PRESSED_NAME_H__
