#ifndef LEETCODE_PROBLEM_1817_H_
#define LEETCODE_PROBLEM_1817_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1817 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&, int)>;

class FindingTheUsersActiveMinutesSolution : public SolutionBase<Func> {
 public:
  FindingTheUsersActiveMinutesSolution();

  std::vector<int> findingUsersActiveMinutes(std::vector<std::vector<int>>& logs,
                                             int k);
};

}  // namespace problem_1817
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1817_H_
