#ifndef LEETCODE_PROBLEMS_REVERSE_STRING_II_H__
#define LEETCODE_PROBLEMS_REVERSE_STRING_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_541 {

using Func = std::function<std::string(std::string, int)>;

class ReverseStringIiSolution : public SolutionBase<Func> {
 public:
  ReverseStringIiSolution();

  std::string reverseStr(std::string s, int k);
};

}  // namespace problem_541
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REVERSE_STRING_II_H__
