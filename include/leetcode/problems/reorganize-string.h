#ifndef LEETCODE_PROBLEMS_REORGANIZE_STRING_H__
#define LEETCODE_PROBLEMS_REORGANIZE_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_767 {

using Func = std::function<std::string(std::string)>;

class ReorganizeStringSolution : public SolutionBase<Func> {
 public:
  ReorganizeStringSolution();

  std::string reorganizeString(const std::string& s) {
    return getSolution()(s);
  }
};

}  // namespace problem_767
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REORGANIZE_STRING_H__
