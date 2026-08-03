#ifndef LEETCODE_PROBLEM_1957_H_
#define LEETCODE_PROBLEM_1957_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1957 {

using Func = std::function<std::string(std::string)>;

class DeleteCharactersToMakeFancyStringSolution : public SolutionBase<Func> {
 public:
  DeleteCharactersToMakeFancyStringSolution();

  std::string makeFancyString(std::string s);
};

}  // namespace problem_1957
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1957_H_
