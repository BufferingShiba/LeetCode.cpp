#ifndef LEETCODE_PROBLEMS_FIND_THE_K_BEAUTY_OF_A_NUMBER_H__
#define LEETCODE_PROBLEMS_FIND_THE_K_BEAUTY_OF_A_NUMBER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2269 {

using Func = std::function<int(int, int)>;

class FindTheKBeautyOfANumberSolution : public SolutionBase<Func> {
 public:
  FindTheKBeautyOfANumberSolution();

  int divisorSubstrings(int num, int k);
};

}  // namespace problem_2269
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_K_BEAUTY_OF_A_NUMBER_H__
