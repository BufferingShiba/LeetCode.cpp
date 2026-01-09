#include "leetcode/utils/stack.h"

namespace leetcode {
MyStack::MyStack() {}

void MyStack::push(int x) { queue_main_.push(x); }

int MyStack::pop() {
  // Move all elements to queue_aux_ except the last one
  while (queue_main_.size() > 1) {
    queue_aux_.push(queue_main_.front());
    queue_main_.pop();
  }
  int result = queue_main_.front();
  queue_main_.pop();

  // Move all elements back to queue_main_
  while (!queue_aux_.empty()) {
    queue_main_.push(queue_aux_.front());
    queue_aux_.pop();
  }
  return result;
}

int MyStack::top() { return queue_main_.back(); }

bool MyStack::empty() { return queue_main_.empty(); };
}  // namespace leetcode