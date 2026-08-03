#ifndef LEETCODE_PROBLEMS_NUMBER_OF_SENIOR_CITIZENS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_SENIOR_CITIZENS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2678 {

using Func = std::function<int(std::vector<std::string>&)>;

class NumberOfSeniorCitizensSolution : public SolutionBase<Func> {
 public:
  NumberOfSeniorCitizensSolution();
  int countSeniors(std::vector<std::string>& details);
};

}  // namespace problem_2678
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_SENIOR_CITIZENS_H__
