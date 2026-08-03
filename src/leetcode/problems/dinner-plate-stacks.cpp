#include "leetcode/problems/dinner-plate-stacks.h"

namespace leetcode {
namespace problem_1172 {

void DinnerPlateStacksSolution::push(int val) {
  // Discard stale entries in the heap (stack removed or already full).
  while (!avail_.empty()) {
    int idx = avail_.top();
    if (idx < static_cast<int>(stacks_.size()) &&
        static_cast<int>(stacks_[idx].size()) < capacity_) {
      break;
    }
    avail_.pop();
  }

  if (!avail_.empty()) {
    int idx = avail_.top();
    avail_.pop();
    stacks_[idx].push(val);
    // If still not full, re-add so it remains available for future push.
    if (static_cast<int>(stacks_[idx].size()) < capacity_) {
      avail_.push(idx);
    }
  } else {
    // No available stack; create a new one.
    if (stacks_.empty() || static_cast<int>(stacks_.back().size()) >= capacity_) {
      stacks_.push_back(std::stack<int>());
    }
    stacks_.back().push(val);
  }
}

int DinnerPlateStacksSolution::pop() {
  // Find rightmost non-empty stack, dropping empty trailing stacks.
  while (!stacks_.empty() && stacks_.back().empty()) {
    stacks_.pop_back();
  }
  if (stacks_.empty()) {
    return -1;
  }

  int idx = static_cast<int>(stacks_.size()) - 1;
  int val = stacks_[idx].top();
  stacks_[idx].pop();
  // This stack is now not full, add it back to available set.
  avail_.push(idx);
  return val;
}

int DinnerPlateStacksSolution::popAtStack(int index) {
  if (index < 0 || index >= static_cast<int>(stacks_.size()) ||
      stacks_[index].empty()) {
    return -1;
  }
  int val = stacks_[index].top();
  stacks_[index].pop();
  // This stack is now not full (it had at least 1 element before). Add it.
  avail_.push(index);
  return val;
}

}  // namespace problem_1172
}  // namespace leetcode
