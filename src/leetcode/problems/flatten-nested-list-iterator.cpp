#include "leetcode/problems/flatten-nested-list-iterator.h"

namespace leetcode::problem_341 {

NestedIterator::NestedIterator(std::vector<NestedInteger>& nestedList) {
  // Push all elements in reverse order onto the stack
  for (int i = static_cast<int>(nestedList.size()) - 1; i >= 0; --i) {
    stack_.push(nestedList[i]);
  }
}

void NestedIterator::ensureTopIsInteger() {
  // While the top of the stack is a list, expand it
  while (!stack_.empty() && !stack_.top().isInteger()) {
    NestedInteger top = stack_.top();
    stack_.pop();
    const auto& subList = top.getList();
    for (int i = static_cast<int>(subList.size()) - 1; i >= 0; --i) {
      stack_.push(subList[i]);
    }
  }
}

bool NestedIterator::hasNext() {
  ensureTopIsInteger();
  return !stack_.empty();
}

int NestedIterator::next() {
  ensureTopIsInteger();
  int val = stack_.top().getInteger();
  stack_.pop();
  return val;
}

std::vector<int> FlattenNestedListIteratorSolution::flatten(
    std::vector<NestedInteger>& nestedList) {
  NestedIterator it(nestedList);
  std::vector<int> result;
  while (it.hasNext()) {
    result.push_back(it.next());
  }
  return result;
}

}  // namespace leetcode::problem_341
