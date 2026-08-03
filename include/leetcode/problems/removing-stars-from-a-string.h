#ifndef LEETCODE_PROBLEMS_REMOVING_STARS_FROM_A_STRING_H_
#define LEETCODE_PROBLEMS_REMOVING_STARS_FROM_A_STRING_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2390 {

using Func = std::function<std::string(std::string)>;

class RemovingStarsFromAStringSolution : public SolutionBase<Func> {
 public:
  RemovingStarsFromAStringSolution();

  std::string removeStars(std::string s);
};

}  // namespace leetcode::problem_2390

#endif  // LEETCODE_PROBLEMS_REMOVING_STARS_FROM_A_STRING_H_
