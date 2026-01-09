#include "leetcode/utils/queue.h"

namespace leetcode {
MyQueue::MyQueue() {}

void MyQueue::move() {
  while (!stack_input_.empty()) {
    stack_output_.push(stack_input_.top());
    stack_input_.pop();
  }
}

void MyQueue::push(int x) { stack_input_.push(x); }

int MyQueue::pop() {
  if (stack_output_.empty()) {
    move();
  }
  int top = stack_output_.top();
  stack_output_.pop();
  return top;
}

int MyQueue::peek() {
  if (stack_output_.empty()) {
    move();
  }
  return stack_output_.top();
}

bool MyQueue::empty() { return stack_input_.empty() && stack_output_.empty(); }
}  // namespace leetcode