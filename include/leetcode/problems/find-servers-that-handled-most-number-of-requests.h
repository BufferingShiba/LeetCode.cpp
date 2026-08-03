#ifndef LEETCODE_PROBLEMS_FIND_SERVERS_THAT_HANDLED_MOST_NUMBER_OF_REQUESTS_H_
#define LEETCODE_PROBLEMS_FIND_SERVERS_THAT_HANDLED_MOST_NUMBER_OF_REQUESTS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1606 {

using Func = std::function<std::vector<int>(int, std::vector<int>&, std::vector<int>&)>;

class FindServersThatHandledMostNumberOfRequestsSolution : public SolutionBase<Func> {
 public:
  FindServersThatHandledMostNumberOfRequestsSolution();

  std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load);
};

}  // namespace problem_1606
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_SERVERS_THAT_HANDLED_MOST_NUMBER_OF_REQUESTS_H_
