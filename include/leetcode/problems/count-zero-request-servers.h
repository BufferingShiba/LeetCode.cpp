#ifndef LEETCODE_PROBLEMS_COUNT_ZERO_REQUEST_SERVERS_H__
#define LEETCODE_PROBLEMS_COUNT_ZERO_REQUEST_SERVERS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2747 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&, int, std::vector<int>&)>;

class CountZeroRequestServersSolution : public SolutionBase<Func> {
 public:
  CountZeroRequestServersSolution();
  std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x,
                                std::vector<int>& queries);
};

}  // namespace problem_2747
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_ZERO_REQUEST_SERVERS_H__
