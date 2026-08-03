#ifndef LEETCODE_PROBLEMS_PASS_THE_PILLOW_H
#define LEETCODE_PROBLEMS_PASS_THE_PILLOW_H

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2582 {

using Func = std::function<int(int n, int time)>;

class PassThePillowSolution : public SolutionBase<Func> {
 public:
  PassThePillowSolution();

  int passThePillow(int n, int time);
};

}  // namespace problem_2582
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PASS_THE_PILLOW_H
