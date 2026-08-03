#ifndef LEETCODE_PROBLEMS_HAPPY_STUDENTS_H__
#define LEETCODE_PROBLEMS_HAPPY_STUDENTS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2860 {

using Func = std::function<int(std::vector<int>&)>;

class HappyStudentsSolution : public SolutionBase<Func> {
 public:
  HappyStudentsSolution();
  int countWays(std::vector<int>& nums);
};

}  // namespace problem_2860
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_HAPPY_STUDENTS_H__
