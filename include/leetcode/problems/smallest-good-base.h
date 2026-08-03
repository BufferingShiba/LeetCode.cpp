#ifndef LEETCODE_PROBLEMS_SMALLEST_GOOD_BASE_H__
#define LEETCODE_PROBLEMS_SMALLEST_GOOD_BASE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_483 {

using Func = std::function<std::string(std::string)>;

class SmallestGoodBaseSolution : public SolutionBase<Func> {
 public:
  SmallestGoodBaseSolution();

  std::string smallestGoodBase(std::string n);
};

}  // namespace problem_483
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_GOOD_BASE_H__
