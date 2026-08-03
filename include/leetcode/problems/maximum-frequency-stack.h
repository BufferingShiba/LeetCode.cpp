#ifndef LEETCODE_MAXIMUM_FREQUENCY_STACK_H__
#define LEETCODE_MAXIMUM_FREQUENCY_STACK_H__

#include <stack>
#include <unordered_map>

namespace leetcode {
namespace problem_895 {

class FreqStack {
 public:
  FreqStack();
  void push(int val);
  int pop();

 private:
  std::unordered_map<int, int> freq_;               // val -> frequency
  std::unordered_map<int, std::stack<int>> group_;   // frequency -> stack of vals
  int max_freq_;
};

}  // namespace problem_895
}  // namespace leetcode

#endif  // LEETCODE_MAXIMUM_FREQUENCY_STACK_H__
