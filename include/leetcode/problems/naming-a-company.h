#ifndef LEETCODE_PROBLEM_2306_H_
#define LEETCODE_PROBLEM_2306_H_

#include "leetcode/core.h"

namespace leetcode::problem_2306 {

using Func = std::function<long long(std::vector<std::string>&)>;

class NamingACompanySolution : public SolutionBase<Func> {
 public:
  NamingACompanySolution();
  long long distinctNames(std::vector<std::string>& ideas);
};

}  // namespace leetcode::problem_2306

#endif  // LEETCODE_PROBLEM_2306_H_
