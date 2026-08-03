#ifndef LEETCODE_PROBLEMS_FLATTEN_NESTED_LIST_ITERATOR_H_
#define LEETCODE_PROBLEMS_FLATTEN_NESTED_LIST_ITERATOR_H_

#include <stack>
#include <variant>
#include <vector>

namespace leetcode::problem_341 {

// NestedInteger implementation matching LeetCode's interface
class NestedInteger {
 public:
  NestedInteger() : data_(0) {}
  explicit NestedInteger(int value) : data_(value) {}
  explicit NestedInteger(std::vector<NestedInteger> list)
      : data_(std::move(list)) {}

  bool isInteger() const { return std::holds_alternative<int>(data_); }

  int getInteger() const { return std::get<int>(data_); }

  const std::vector<NestedInteger>& getList() const {
    return std::get<std::vector<NestedInteger>>(data_);
  }

 private:
  std::variant<int, std::vector<NestedInteger>> data_;
};

// NestedIterator — matches LeetCode's required interface
class NestedIterator {
 public:
  explicit NestedIterator(std::vector<NestedInteger>& nestedList);
  int next();
  bool hasNext();

 private:
  std::stack<NestedInteger> stack_;
  void ensureTopIsInteger();
};

// Solution wrapper for testing
class FlattenNestedListIteratorSolution {
 public:
  std::vector<int> flatten(std::vector<NestedInteger>& nestedList);
};

}  // namespace leetcode::problem_341

#endif  // LEETCODE_PROBLEMS_FLATTEN_NESTED_LIST_ITERATOR_H_
