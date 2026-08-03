#ifndef LEETCODE_PROBLEMS_SHIFTING_LETTERS_II_H_
#define LEETCODE_PROBLEMS_SHIFTING_LETTERS_II_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2381 {

using Func = std::function<std::string(std::string, std::vector<std::vector<int>>&)>;

class ShiftingLettersIiSolution : public SolutionBase<Func> {
 public:
  ShiftingLettersIiSolution();

  std::string shiftingLetters(std::string s,
                              std::vector<std::vector<int>>& shifts);
};

}  // namespace problem_2381
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHIFTING_LETTERS_II_H_
