#ifndef LEETCODE_PROBLEMS_REVERSE_STRING_H__
#define LEETCODE_PROBLEMS_REVERSE_STRING_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_344 {

using Func = std::function<void(std::vector<char>&)>;

class ReverseStringSolution : public SolutionBase<Func> {
 public:
  ReverseStringSolution();
  void reverseString(std::vector<char>& s);
};

}  // namespace problem_344
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REVERSE_STRING_H__
