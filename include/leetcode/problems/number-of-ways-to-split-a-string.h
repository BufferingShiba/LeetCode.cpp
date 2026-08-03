#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SPLIT_A_STRING_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SPLIT_A_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1573 {

using Func = std::function<int(std::string)>;

class NumberOfWaysToSplitAStringSolution : public SolutionBase<Func> {
 public:
  NumberOfWaysToSplitAStringSolution();

  int numWays(std::string s);
};

}  // namespace problem_1573
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_SPLIT_A_STRING_H__
