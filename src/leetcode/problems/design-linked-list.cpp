#include "leetcode/problems/design-linked-list.h"

namespace problem_707 {

MyLinkedList::MyLinkedList() : dummy_(new Node(0)), size_(0) {}

MyLinkedList::~MyLinkedList() {
  Node* cur = dummy_;
  while (cur != nullptr) {
    Node* next = cur->next;
    delete cur;
    cur = next;
  }
}

int MyLinkedList::get(int index) {
  if (index < 0 || index >= size_) {
    return -1;
  }
  Node* cur = dummy_->next;
  for (int i = 0; i < index; ++i) {
    cur = cur->next;
  }
  return cur->val;
}

void MyLinkedList::addAtHead(int val) {
  dummy_->next = new Node(val, dummy_->next);
  ++size_;
}

void MyLinkedList::addAtTail(int val) {
  Node* cur = dummy_;
  while (cur->next != nullptr) {
    cur = cur->next;
  }
  cur->next = new Node(val);
  ++size_;
}

void MyLinkedList::addAtIndex(int index, int val) {
  if (index < 0 || index > size_) {
    return;
  }
  Node* prev = dummy_;
  for (int i = 0; i < index; ++i) {
    prev = prev->next;
  }
  prev->next = new Node(val, prev->next);
  ++size_;
}

void MyLinkedList::deleteAtIndex(int index) {
  if (index < 0 || index >= size_) {
    return;
  }
  Node* prev = dummy_;
  for (int i = 0; i < index; ++i) {
    prev = prev->next;
  }
  Node* del = prev->next;
  prev->next = del->next;
  delete del;
  --size_;
}

}  // namespace problem_707
