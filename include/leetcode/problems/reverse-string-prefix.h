#ifndef LEETCODE_PROBLEMS_REVERSE_STRING_PREFIX_H__
#define LEETCODE_PROBLEMS_REVERSE_STRING_PREFIX_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_3794 {

using Func = std::function<std::string(std::string, int)>;

class ReverseStringPrefix : public SolutionBase<Func> {
 public:
  ReverseStringPrefix();

  std::string reversePrefix(std::string s, int k);
};

}  // namespace problem_3794
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REVERSE_STRING_PREFIX_H__
