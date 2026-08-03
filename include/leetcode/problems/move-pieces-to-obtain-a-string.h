#ifndef LEETCODE_PROBLEMS_MOVE_PIECES_TO_OBTAIN_A_STRING_H_
#define LEETCODE_PROBLEMS_MOVE_PIECES_TO_OBTAIN_A_STRING_H_

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2337 {

using Func = std::function<bool(std::string, std::string)>;

class MovePiecesToObtainAStringSolution : public SolutionBase<Func> {
 public:
  MovePiecesToObtainAStringSolution();
  bool canChange(std::string start, std::string target);
};

}  // namespace problem_2337
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MOVE_PIECES_TO_OBTAIN_A_STRING_H_
