#ifndef LEETCODE_PROBLEMS_MAXIMUM_69_NUMBER_H__
#define LEETCODE_PROBLEMS_MAXIMUM_69_NUMBER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1323 {

using Func = std::function<int(int)>;

class Maximum69NumberSolution : public SolutionBase<Func> {
 public:
  int maximum69Number(int num);

  Maximum69NumberSolution();
};

}  // namespace problem_1323
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_69_NUMBER_H__
