#ifndef LEETCODE_PROBLEMS_FIND_THE_SHORTEST_SUPERSTRING_H_
#define LEETCODE_PROBLEMS_FIND_THE_SHORTEST_SUPERSTRING_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_943 {

using Func = std::function<std::string(std::vector<std::string>&)>;

class FindTheShortestSuperstringSolution : public SolutionBase<Func> {
 public:
  std::string shortestSuperstring(std::vector<std::string>& words);

  FindTheShortestSuperstringSolution();
};

}  // namespace problem_943
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_SHORTEST_SUPERSTRING_H_
