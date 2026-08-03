#ifndef LEETCODE_PROBLEMS_RESTORE_THE_ARRAY_H_
#define LEETCODE_PROBLEMS_RESTORE_THE_ARRAY_H_

#include <functional>
#include <string>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_1416 {

using Func = std::function<int(std::string, int)>;

class RestoreTheArraySolution : public SolutionBase<Func> {
 public:
  RestoreTheArraySolution();

  int numberOfArrays(std::string s, int k);
};

}  // namespace problem_1416
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RESTORE_THE_ARRAY_H_
