#ifndef LEETCODE_PROBLEMS_TO_LOWER_CASE_H__
#define LEETCODE_PROBLEMS_TO_LOWER_CASE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_709 {

using Func = std::function<std::string(std::string)>;

class ToLowerCaseSolution : public SolutionBase<Func> {
 public:
  std::string toLowerCase(std::string s);

  ToLowerCaseSolution();
};

}  // namespace problem_709
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TO_LOWER_CASE_H__
