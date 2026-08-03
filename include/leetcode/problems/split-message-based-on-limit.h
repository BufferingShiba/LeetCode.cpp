#ifndef LEETCODE_PROBLEMS_SPLIT_MESSAGE_BASED_ON_LIMIT_H__
#define LEETCODE_PROBLEMS_SPLIT_MESSAGE_BASED_ON_LIMIT_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2468 {

using Func = std::function<std::vector<std::string>(std::string, int)>;

class SplitMessageBasedOnLimitSolution : public SolutionBase<Func> {
 public:
  SplitMessageBasedOnLimitSolution();
  std::vector<std::string> splitMessage(std::string message, int limit);
};

}  // namespace problem_2468
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPLIT_MESSAGE_BASED_ON_LIMIT_H__
