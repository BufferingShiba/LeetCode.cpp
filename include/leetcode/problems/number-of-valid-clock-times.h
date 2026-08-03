#ifndef LEETCODE_PROBLEMS_NUMBER_OF_VALID_CLOCK_TIMES_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_VALID_CLOCK_TIMES_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2437 {

using Func = std::function<int(std::string)>;

class NumberOfValidClockTimesSolution : public SolutionBase<Func> {
 public:
  NumberOfValidClockTimesSolution();

  int countTime(std::string time);
};

}  // namespace problem_2437
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_VALID_CLOCK_TIMES_H__
