#ifndef LEETCODE_PROBLEMS_DESIGN_CIRCULAR_DEQUE_H__
#define LEETCODE_PROBLEMS_DESIGN_CIRCULAR_DEQUE_H__

#include "leetcode/core.h"

#include <vector>

namespace leetcode {
namespace problem_641 {

//! Design circular deque (MyCircularDeque) interface.
//! LeetCode problem 641: Design Circular Deque.
class DesignCircularDeque {
 public:
  DesignCircularDeque(int k) : capacity_(k), front_(0), rear_(0), size_(0) {
    data_.resize(k);
  }

  virtual ~DesignCircularDeque() = default;

  //! Adds an item at the front of Deque. Returns true if the operation is
  //! successful, or false otherwise.
  virtual bool insertFront(int value) = 0;

  //! Adds an item at the rear of Deque. Returns true if the operation is
  //! successful, or false otherwise.
  virtual bool insertLast(int value) = 0;

  //! Deletes an item from the front of Deque. Returns true if the operation is
  //! successful, or false otherwise.
  virtual bool deleteFront() = 0;

  //! Deletes an item from the rear of Deque. Returns true if the operation is
  //! successful, or false otherwise.
  virtual bool deleteLast() = 0;

  //! Returns the front item from the Deque. Returns -1 if the deque is empty.
  virtual int getFront() = 0;

  //! Returns the last item from Deque. Returns -1 if the deque is empty.
  virtual int getRear() = 0;

  //! Returns true if the deque is empty, or false otherwise.
  virtual bool isEmpty() = 0;

  //! Returns true if the deque is full, or false otherwise.
  virtual bool isFull() = 0;

 protected:
  int capacity_;
  int front_;
  int rear_;
  int size_;
  std::vector<int> data_;
};

//! Concrete implementation using a circular array buffer.
class DesignCircularDequeSolution : public DesignCircularDeque {
 public:
  explicit DesignCircularDequeSolution(int k);

  bool insertFront(int value) override;
  bool insertLast(int value) override;
  bool deleteFront() override;
  bool deleteLast() override;
  int getFront() override;
  int getRear() override;
  bool isEmpty() override;
  bool isFull() override;
};

}  // namespace problem_641
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DESIGN_CIRCULAR_DEQUE_H__
