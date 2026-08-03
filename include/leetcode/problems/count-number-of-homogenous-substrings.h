#ifndef LEETCODE_PROBLEMS_COUNT_NUMBER_OF_HOMOGENOUS_SUBSTRINGS_H__
#define LEETCODE_PROBLEMS_COUNT_NUMBER_OF_HOMOGENOUS_SUBSTRINGS_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1759 {

using Func = std::function<int(std::string)>;

int countHomogenousImpl(const std::string& s);

class CountNumberOfHomogenousSubstringsSolution : public SolutionBase<Func> {
 public:
  CountNumberOfHomogenousSubstringsSolution() {
    setMetaInfo({1759, "Count Number of Homogenous Substrings",
                 "https://leetcode.com/problems/count-number-of-homogenous-substrings/"});
    registerStrategy({"linear-scan", "Accepted", "O(n)", "O(1)",
                       {"Math", "String"}},
                      countHomogenousImpl);
  }

  int countHomogenous(const std::string& s) {
    return getSolution()(s);
  }
};

}  // namespace problem_1759
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NUMBER_OF_HOMOGENOUS_SUBSTRINGS_H__
