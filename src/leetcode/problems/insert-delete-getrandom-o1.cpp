#include "leetcode/problems/insert-delete-getrandom-o1.h"

#include <cstdlib>

namespace leetcode {
namespace problem_380 {

RandomizedSet::RandomizedSet() = default;

bool RandomizedSet::insert(int val) {
  if (valToIndex_.find(val) != valToIndex_.end()) {
    return false;
  }
  valToIndex_[val] = nums_.size();
  nums_.push_back(val);
  return true;
}

bool RandomizedSet::remove(int val) {
  auto it = valToIndex_.find(val);
  if (it == valToIndex_.end()) {
    return false;
  }
  int index = it->second;
  int lastVal = nums_.back();

  // Move the last element to the deleted position
  nums_[index] = lastVal;
  valToIndex_[lastVal] = index;

  // Remove the last element
  nums_.pop_back();
  valToIndex_.erase(val);
  return true;
}

int RandomizedSet::getRandom() {
  int randomIndex = std::rand() % nums_.size();
  return nums_[randomIndex];
}

}  // namespace problem_380
}  // namespace leetcode
