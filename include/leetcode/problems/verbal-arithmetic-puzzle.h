#ifndef LEETCODE_PROBLEMS_VERBAL_ARITHMETIC_PUZZLE_H_
#define LEETCODE_PROBLEMS_VERBAL_ARITHMETIC_PUZZLE_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1307 {

using Func = std::function<bool(std::vector<std::string>&, std::string)>;

class VerbalArithmeticPuzzleSolution : public SolutionBase<Func> {
 public:
  VerbalArithmeticPuzzleSolution();

  bool isSolvable(std::vector<std::string>& words, std::string result);
};

}  // namespace problem_1307
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VERBAL_ARITHMETIC_PUZZLE_H_
