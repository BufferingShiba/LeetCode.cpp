#include "leetcode/problems/range-module.h"

#include <map>

namespace leetcode {
namespace problem_715 {

void RangeModule::addRange(int left, int right) {
  // Find first interval that might overlap (its right end >= left).
  auto it = ranges_.lower_bound(left);
  if (it != ranges_.begin() && std::prev(it)->second >= left) {
    --it;
  }
  while (it != ranges_.end() && it->first <= right) {
    left = std::min(left, it->first);
    right = std::max(right, it->second);
    it = ranges_.erase(it);
  }
  ranges_[left] = right;
}

bool RangeModule::queryRange(int left, int right) {
  auto it = ranges_.upper_bound(left);
  if (it == ranges_.begin()) {
    return false;
  }
  --it;
  return it->second >= right;
}

void RangeModule::removeRange(int left, int right) {
  auto it = ranges_.lower_bound(left);
  if (it != ranges_.begin() && std::prev(it)->second > left) {
    --it;
  }
  while (it != ranges_.end() && it->first < right) {
    const int l = it->first;
    const int r = it->second;
    it = ranges_.erase(it);
    if (l < left) {
      ranges_[l] = left;
    }
    if (r > right) {
      ranges_[right] = r;
    }
  }
}

}  // namespace problem_715
}  // namespace leetcode
