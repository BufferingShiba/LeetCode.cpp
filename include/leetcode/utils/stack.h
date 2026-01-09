#ifndef LEETCODE_UTILS_STACK_H__
#define LEETCODE_UTILS_STACK_H__

#include <queue>

namespace leetcode {
class MyStack {
 public:
  MyStack();

  void push(int x);

  int pop();

  int top();

  bool empty();

 private:
  std::queue<int> queue_main_;
  std::queue<int> queue_aux_;
};
}  // namespace leetcode

#endif  // LEETCODE_UTILS_STACK_H__