#ifndef LEETCODE_PROBLEMS_BUDDY_STRINGS_H__
#define LEETCODE_PROBLEMS_BUDDY_STRINGS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_859 {

using Func = std::function<bool(std::string, std::string)>;

class BuddyStringsSolution : public SolutionBase<Func> {
 public:
  BuddyStringsSolution();

  bool buddyStrings(std::string s, std::string goal);
};

}  // namespace problem_859
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BUDDY_STRINGS_H__
