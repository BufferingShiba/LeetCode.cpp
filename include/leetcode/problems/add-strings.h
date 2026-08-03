#ifndef LEETCODE_PROBLEMS_ADD_STRINGS_H_
#define LEETCODE_PROBLEMS_ADD_STRINGS_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_415 {

using Func = std::function<std::string(std::string, std::string)>;

class AddStringsSolution : public SolutionBase<Func> {
 public:
  AddStringsSolution();
  std::string addStrings(std::string num1, std::string num2);
};

}  // namespace problem_415
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ADD_STRINGS_H_
