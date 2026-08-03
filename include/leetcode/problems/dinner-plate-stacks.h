#ifndef LEETCODE_PROBLEMS_DINNER_PLATE_STACKS_H__
#define LEETCODE_PROBLEMS_DINNER_PLATE_STACKS_H__

#include <queue>
#include <stack>
#include <vector>

namespace leetcode {
namespace problem_1172 {

class DinnerPlateStacksSolution {
 public:
  DinnerPlateStacksSolution(int capacity) : capacity_(capacity) {}

  void push(int val);
  int pop();
  int popAtStack(int index);

 private:
  int capacity_;
  std::vector<std::stack<int>> stacks_;
  // Min-heap of stack indices that are currently not full.
  std::priority_queue<int, std::vector<int>, std::greater<int>> avail_;
};

}  // namespace problem_1172
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DINNER_PLATE_STACKS_H__
