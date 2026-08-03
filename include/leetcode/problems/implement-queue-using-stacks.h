#ifndef LEETCODE_PROBLEMS_IMPLEMENT_QUEUE_USING_STACKS_H_
#define LEETCODE_PROBLEMS_IMPLEMENT_QUEUE_USING_STACKS_H_

#include <stack>

namespace leetcode {
namespace problem_232 {

class MyQueue {
 public:
  MyQueue();
  void push(int x);
  int pop();
  int peek();
  bool empty();

 private:
  std::stack<int> in_;
  std::stack<int> out_;
  void transfer();
};

}  // namespace problem_232
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_IMPLEMENT_QUEUE_USING_STACKS_H_
