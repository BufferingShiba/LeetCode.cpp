#ifndef LEETCODE_PROBLEM_2380_H
#define LEETCODE_PROBLEM_2380_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2380 {

using Func = std::function<int(std::string)>;

class TimeNeededToRearrangeABinaryStringSolution : public SolutionBase<Func> {
 public:
  TimeNeededToRearrangeABinaryStringSolution();
  int secondsToRemoveOccurrences(std::string s);
};

}  // namespace problem_2380
}  // namespace leetcode

#endif
