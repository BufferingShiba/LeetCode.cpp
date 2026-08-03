#ifndef LEETCODE_PROBLEMS_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_H__
#define LEETCODE_PROBLEMS_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1047 {

using Func = std::function<std::string(std::string)>;

class RemoveAllAdjacentDuplicatesInStringSolution
    : public SolutionBase<Func> {
 public:
  RemoveAllAdjacentDuplicatesInStringSolution();

  std::string removeDuplicates(std::string s);
};

}  // namespace problem_1047
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_H__
