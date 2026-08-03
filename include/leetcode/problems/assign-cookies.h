#ifndef LEETCODE_PROBLEMS_ASSIGN_COOKIES_H_
#define LEETCODE_PROBLEMS_ASSIGN_COOKIES_H_

#include <functional>
#include <vector>
#include "leetcode/core.h"

namespace leetcode::problem_455 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class AssignCookiesSolution : public SolutionBase<Func> {
 public:
  AssignCookiesSolution();

  int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    return getSolution()(g, s);
  }
};

}  // namespace leetcode::problem_455

#endif  // LEETCODE_PROBLEMS_ASSIGN_COOKIES_H_
