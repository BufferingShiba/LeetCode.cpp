#ifndef LEETCODE_PROBLEMS_REMOVE_ALL_OCCURRENCES_OF_A_SUBSTRING_H_
#define LEETCODE_PROBLEMS_REMOVE_ALL_OCCURRENCES_OF_A_SUBSTRING_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1910 {

using Func = std::function<std::string(std::string, std::string)>;

class RemoveAllOccurrencesOfASubstringSolution : public SolutionBase<Func> {
 public:
  RemoveAllOccurrencesOfASubstringSolution();

  std::string removeOccurrences(std::string s, std::string part);
};

}  // namespace problem_1910
}  // namespace leetcode

#endif
