#ifndef LEETCODE_PROBLEMS_CONSTRUCT_THE_LONGEST_NEW_STRING_H_
#define LEETCODE_PROBLEMS_CONSTRUCT_THE_LONGEST_NEW_STRING_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2745 {

using Func = std::function<int(int, int, int)>;

class ConstructTheLongestNewStringSolution : public SolutionBase<Func> {
 public:
  ConstructTheLongestNewStringSolution();

  int longestString(int x, int y, int z);
};

}  // namespace problem_2745
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_THE_LONGEST_NEW_STRING_H_
