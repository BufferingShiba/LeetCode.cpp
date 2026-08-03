#ifndef LEETCODE_PROBLEMS_FIND_THE_PUNISHMENT_NUMBER_OF_AN_INTEGER_H__
#define LEETCODE_PROBLEMS_FIND_THE_PUNISHMENT_NUMBER_OF_AN_INTEGER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2698 {

using Func = std::function<int(int)>;

// Find the Punishment Number of an Integer
// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
class FindThePunishmentNumberOfAnIntegerSolution
    : public SolutionBase<Func> {
 public:
  FindThePunishmentNumberOfAnIntegerSolution();

  int punishmentNumber(int n);
};

}  // namespace problem_2698
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_PUNISHMENT_NUMBER_OF_AN_INTEGER_H__
