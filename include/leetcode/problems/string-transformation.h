#ifndef LEETCODE_PROBLEMS_STRING_TRANSFORMATION_H__
#define LEETCODE_PROBLEMS_STRING_TRANSFORMATION_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_2851 {

using Func = std::function<int(std::string, std::string, long long)>;

class StringTransformationSolution
    : public SolutionBase<Func> {
 public:
  StringTransformationSolution();
  int numberOfWays(std::string s, std::string t, long long k);
};

}  // namespace leetcode::problem_2851

#endif  // LEETCODE_PROBLEMS_STRING_TRANSFORMATION_H__
