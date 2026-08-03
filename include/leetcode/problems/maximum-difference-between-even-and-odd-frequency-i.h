#ifndef LEETCODE_PROBLEM_3442_H_
#define LEETCODE_PROBLEM_3442_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_3442 {

using Func = std::function<int(std::string)>;

class MaximumDifferenceBetweenEvenAndOddFrequencyISolution : public SolutionBase<Func> {
 public:
  MaximumDifferenceBetweenEvenAndOddFrequencyISolution();

  int maxDifference(std::string s);
};

}  // namespace problem_3442
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3442_H_
