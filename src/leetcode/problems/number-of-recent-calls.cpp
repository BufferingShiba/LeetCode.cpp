#include "leetcode/problems/number-of-recent-calls.h"

namespace leetcode::problem_933 {

RecentCounter::RecentCounter() {}

int RecentCounter::ping(int t) {
  q_.push(t);
  while (q_.front() < t - 3000) {
    q_.pop();
  }
  return static_cast<int>(q_.size());
}

}  // namespace leetcode::problem_933
