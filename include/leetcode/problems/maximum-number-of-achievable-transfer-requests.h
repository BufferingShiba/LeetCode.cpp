#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_ACHIEVABLE_TRANSFER_REQUESTS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_ACHIEVABLE_TRANSFER_REQUESTS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1601 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class MaximumNumberOfAchievableTransferRequestsSolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfAchievableTransferRequestsSolution();

  int maximumRequests(int n, std::vector<std::vector<int>>& requests);
};

}  // namespace problem_1601
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_ACHIEVABLE_TRANSFER_REQUESTS_H__
