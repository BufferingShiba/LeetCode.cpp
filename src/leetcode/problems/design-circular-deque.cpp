#include "leetcode/problems/design-circular-deque.h"

namespace leetcode {
namespace problem_641 {

DesignCircularDequeSolution::DesignCircularDequeSolution(int k)
    : DesignCircularDeque(k) {}

bool DesignCircularDequeSolution::insertFront(int value) {
  if (isFull()) {
    return false;
  }
  front_ = (front_ - 1 + capacity_) % capacity_;
  data_[front_] = value;
  ++size_;
  return true;
}

bool DesignCircularDequeSolution::insertLast(int value) {
  if (isFull()) {
    return false;
  }
  data_[rear_] = value;
  rear_ = (rear_ + 1) % capacity_;
  ++size_;
  return true;
}

bool DesignCircularDequeSolution::deleteFront() {
  if (isEmpty()) {
    return false;
  }
  front_ = (front_ + 1) % capacity_;
  --size_;
  return true;
}

bool DesignCircularDequeSolution::deleteLast() {
  if (isEmpty()) {
    return false;
  }
  rear_ = (rear_ - 1 + capacity_) % capacity_;
  --size_;
  return true;
}

int DesignCircularDequeSolution::getFront() {
  if (isEmpty()) {
    return -1;
  }
  return data_[front_];
}

int DesignCircularDequeSolution::getRear() {
  if (isEmpty()) {
    return -1;
  }
  return data_[(rear_ - 1 + capacity_) % capacity_];
}

bool DesignCircularDequeSolution::isEmpty() { return size_ == 0; }

bool DesignCircularDequeSolution::isFull() { return size_ == capacity_; }

}  // namespace problem_641
}  // namespace leetcode
