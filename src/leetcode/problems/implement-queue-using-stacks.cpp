#include "leetcode/problems/implement-queue-using-stacks.h"

namespace leetcode {
namespace problem_232 {

MyQueue::MyQueue() = default;

void MyQueue::transfer() {
  if (out_.empty()) {
    while (!in_.empty()) {
      out_.push(in_.top());
      in_.pop();
    }
  }
}

void MyQueue::push(int x) { in_.push(x); }

int MyQueue::pop() {
  transfer();
  int front = out_.top();
  out_.pop();
  return front;
}

int MyQueue::peek() {
  transfer();
  return out_.top();
}

bool MyQueue::empty() { return in_.empty() && out_.empty(); }

}  // namespace problem_232
}  // namespace leetcode
