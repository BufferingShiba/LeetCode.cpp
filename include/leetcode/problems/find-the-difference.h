#ifndef LEETCODE_PROBLEMS_FIND_THE_DIFFERENCE_H__
#define LEETCODE_PROBLEMS_FIND_THE_DIFFERENCE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_389 {

using Func = std::function<char(std::string, std::string)>;

class FindTheDifferenceSolution : public SolutionBase<Func> {
 public:
  FindTheDifferenceSolution();

  char findTheDifference(std::string s, std::string t);
};

}  // namespace problem_389
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_DIFFERENCE_H__
