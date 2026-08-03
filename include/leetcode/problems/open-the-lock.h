#ifndef LEETCODE_PROBLEMS_OPEN_THE_LOCK_H__
#define LEETCODE_PROBLEMS_OPEN_THE_LOCK_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_752 {

using Func = std::function<int(std::vector<std::string>&, std::string)>;

class OpenTheLockSolution : public SolutionBase<Func> {
 public:
  OpenTheLockSolution();

  int openLock(std::vector<std::string>& deadends, std::string target);
};

}  // namespace problem_752
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_OPEN_THE_LOCK_H__
