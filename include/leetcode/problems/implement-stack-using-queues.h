#ifndef LEETCODE_PROBLEMS_IMPLEMENT_STACK_USING_QUEUES_H_
#define LEETCODE_PROBLEMS_IMPLEMENT_STACK_USING_QUEUES_H_

#include <queue>

namespace leetcode::problem_225 {

// MyStack implements a LIFO stack using a single queue.
// push is O(n): after enqueuing x, rotate the rest to keep x at the front.
// pop/top/empty are O(1).
class MyStack {
 public:
  MyStack() = default;

  void push(int x) {
    q_.push(x);
    for (int i = 0; i + 1 < static_cast<int>(q_.size()); ++i) {
      q_.push(q_.front());
      q_.pop();
    }
  }

  int pop() {
    int top = q_.front();
    q_.pop();
    return top;
  }

  int top() const {
    return q_.front();
  }

  bool empty() const {
    return q_.empty();
  }

 private:
  std::queue<int> q_;
};

}  // namespace leetcode::problem_225

#endif  // LEETCODE_PROBLEMS_IMPLEMENT_STACK_USING_QUEUES_H_
