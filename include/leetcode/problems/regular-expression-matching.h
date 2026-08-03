#ifndef LEETCODE_PROBLEMS_REGULAR_EXPRESSION_MATCHING_H__
#define LEETCODE_PROBLEMS_REGULAR_EXPRESSION_MATCHING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_10 {

using Func = std::function<bool(std::string, std::string)>;

class RegularExpressionMatchingSolution : public SolutionBase<Func> {
 public:
  RegularExpressionMatchingSolution();

  bool isMatch(std::string s, std::string p) {
    return getSolution()(std::move(s), std::move(p));
  }
};

}  // namespace problem_10
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REGULAR_EXPRESSION_MATCHING_H__
