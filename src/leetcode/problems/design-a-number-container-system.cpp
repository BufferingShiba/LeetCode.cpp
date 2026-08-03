#include "leetcode/problems/design-a-number-container-system.h"

namespace leetcode {
namespace problem_2349 {

NumberContainers::NumberContainers() {}

void NumberContainers::change(int index, int number) {
  auto it = idx_to_num_.find(index);
  if (it != idx_to_num_.end()) {
    int old_num = it->second;
    if (old_num == number) return;
    num_to_indices_[old_num].erase(index);
    if (num_to_indices_[old_num].empty()) {
      num_to_indices_.erase(old_num);
    }
  }
  idx_to_num_[index] = number;
  num_to_indices_[number].insert(index);
}

int NumberContainers::find(int number) {
  auto it = num_to_indices_.find(number);
  if (it != num_to_indices_.end() && !it->second.empty()) {
    return *it->second.begin();
  }
  return -1;
}

}  // namespace problem_2349
}  // namespace leetcode
