#include "leetcode/problems/maximum-frequency-stack.h"

namespace leetcode {
namespace problem_895 {

FreqStack::FreqStack() : max_freq_(0) {}

void FreqStack::push(int val) {
  int f = ++freq_[val];
  group_[f].push(val);
  if (f > max_freq_) {
    max_freq_ = f;
  }
}

int FreqStack::pop() {
  auto& st = group_[max_freq_];
  int val = st.top();
  st.pop();
  --freq_[val];
  if (st.empty()) {
    group_.erase(max_freq_);
    --max_freq_;
  }
  return val;
}

}  // namespace problem_895
}  // namespace leetcode
