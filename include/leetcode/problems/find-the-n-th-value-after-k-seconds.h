#ifndef LEETCODE_PROBLEMS_FIND_THE_N_TH_VALUE_AFTER_K_SECONDS_H__
#define LEETCODE_PROBLEMS_FIND_THE_N_TH_VALUE_AFTER_K_SECONDS_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_3179 {

using Func = std::function<int(int, int)>;

class FindTheNThValueAfterKSecondsSolution
    : public SolutionBase<Func> {
 public:
  FindTheNThValueAfterKSecondsSolution();

  int valueAfterKSeconds(int n, int k);
};

}  // namespace problem_3179
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_N_TH_VALUE_AFTER_K_SECONDS_H__
