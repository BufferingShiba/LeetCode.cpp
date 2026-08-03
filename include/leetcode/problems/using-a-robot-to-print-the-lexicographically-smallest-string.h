#ifndef LEETCODE_PROBLEM_2434_H_
#define LEETCODE_PROBLEM_2434_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2434 {

using Func = std::function<std::string(std::string)>;

class UsingARobotToPrintTheLexicographicallySmallestStringSolution
    : public SolutionBase<Func> {
 public:
  UsingARobotToPrintTheLexicographicallySmallestStringSolution();

  std::string robotWithString(std::string s);
};

}  // namespace problem_2434
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2434_H_
