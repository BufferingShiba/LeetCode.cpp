#ifndef LEETCODE_PROBLEMS_MINIMUM_WINDOW_SUBSTRING_H_
#define LEETCODE_PROBLEMS_MINIMUM_WINDOW_SUBSTRING_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_76 {

using Func = std::function<std::string(std::string, std::string)>;

class MinimumWindowSubstringSolution : public SolutionBase<Func> {
 public:
  MinimumWindowSubstringSolution();

  std::string minWindow(std::string s, std::string t);
};

}  // namespace problem_76
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_WINDOW_SUBSTRING_H_
