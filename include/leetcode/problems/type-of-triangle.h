#ifndef LEETCODE_PROBLEM_3024_H_
#define LEETCODE_PROBLEM_3024_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3024 {

using Func = std::function<std::string(std::vector<int>&)>;

class TypeOfTriangleSolution : public SolutionBase<Func> {
 public:
  TypeOfTriangleSolution();

  std::string triangleType(std::vector<int>& nums);
};

}  // namespace problem_3024
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3024_H_
