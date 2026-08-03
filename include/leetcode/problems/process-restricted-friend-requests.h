#ifndef LEETCODE_PROBLEMS_PROCESS_RESTRICTED_FRIEND_REQUESTS_H__
#define LEETCODE_PROBLEMS_PROCESS_RESTRICTED_FRIEND_REQUESTS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_2076 {

using Func = std::function<std::vector<bool>(
    int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class ProcessRestrictedFriendRequestsSolution
    : public SolutionBase<Func> {
 public:
  ProcessRestrictedFriendRequestsSolution();

  std::vector<bool> friendRequests(
      int n, std::vector<std::vector<int>>& restrictions,
      std::vector<std::vector<int>>& requests);
};

}  // namespace leetcode::problem_2076

#endif  // LEETCODE_PROBLEMS_PROCESS_RESTRICTED_FRIEND_REQUESTS_H__
