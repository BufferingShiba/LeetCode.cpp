#ifndef LEETCODE_NUMBER_OF_RECENT_CALLS_H__
#define LEETCODE_NUMBER_OF_RECENT_CALLS_H__

#include "leetcode/core.h"

#include <queue>

namespace leetcode::problem_933 {

class RecentCounter {
 public:
  RecentCounter();
  int ping(int t);

 private:
  std::queue<int> q_;
};

}  // namespace leetcode::problem_933

#endif  // LEETCODE_NUMBER_OF_RECENT_CALLS_H__
