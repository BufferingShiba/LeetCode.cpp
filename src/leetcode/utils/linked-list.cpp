#include "leetcode/utils/linked-list.h"

namespace leetcode {

ListNode* constructLinkedList(const std::vector<int>& nums) {
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  for (int num : nums) {
    if (!head) {
      head = new ListNode(num);
      tail = head;
    } else {
      tail->next = new ListNode(num);
      tail = tail->next;
    }
  }
  return head;
}

std::vector<int> traverse(ListNode* head) {
  std::vector<int> result;
  while (head) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}

ListNode* removeElements(ListNode* head, int val) {
  ListNode* dummy = new ListNode(0, head);
  ListNode* cur = dummy;
  while (cur->next != nullptr) {
    if (cur->next->val == val) {
      ListNode* tmp = cur->next;
      cur->next = cur->next->next;
      delete tmp;
    } else {
      cur = cur->next;
    }
  }
  head = dummy->next;
  delete dummy;
  return head;
}

ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* cur = head;
  ListNode* next = nullptr;
  while (cur != nullptr) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

ListNode* getNode(ListNode* head, int index) {
  if (index < 0) {
    return nullptr;
  }
  ListNode dummy(0, head);
  ListNode* cur = &dummy;
  for (int i = 0; i <= index; ++i) {
    cur = cur->next;
    if (cur == nullptr) {
      return nullptr;  // index 超出范围
    }
  }
  return cur;
};

ListNode* getTail(ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }
  ListNode* cur = head;
  while (cur->next != nullptr) {
    cur = cur->next;
  }
  return cur;
}

/* MyLinkedList */

MyLinkedList::MyLinkedList(ListNode* head)
    : head_(head), tail_(nullptr), dummy_(0), size_(0) {
  ListNode* cur = head;
  while (cur) {
    ++size_;
    tail_ = cur;
    cur = cur->next;
  }
  dummy_.next = head_;
}

MyLinkedList::~MyLinkedList() {
  while (head_) {
    ListNode* tmp = head_;
    head_ = head_->next;
    delete tmp;
  }
}

ListNode* MyLinkedList::getNode(int index) {
  dummy_.next = head_;
  ListNode* cur = &dummy_;
  for (int i = 0; i <= index; ++i) {
    cur = cur->next;
  }
  return cur;
};

int MyLinkedList::get(int index) {
  if (index < 0 || index >= size_) {
    return -1;
  }
  return getNode(index)->val;
}

void MyLinkedList::addAtHead(int val) {
  head_ = new ListNode(val, head_);
  if (size_++ == 0) {  // empty list before adding
    tail_ = head_;
  }
}

void MyLinkedList::addAtTail(int val) {
  if (size_++ == 0) {  // empty list before adding
    head_ = tail_ = new ListNode(val);
  } else {
    tail_->next = new ListNode(val);
    tail_ = tail_->next;
  }
}

void MyLinkedList::addAtIndex(int index, int val) {
  if (index < 0 || index > size_) {
    return;
  }
  if (index == 0) {
    addAtHead(val);
  } else if (index == size_) {
    addAtTail(val);
  } else {
    ListNode* prev = getNode(index - 1);
    prev->next = new ListNode(val, prev->next);
    ++size_;
  }
}

void MyLinkedList::deleteAtIndex(int index) {
  if (index < 0 || index >= size_) {
    return;
  }
  bool is_tail = (index == size_ - 1);  // 在 size_ 减1之前检查
  ListNode* prev = getNode(index - 1);
  ListNode* del = prev->next;
  prev->next = del->next;
  delete del;
  --size_;
  if (size_ == 0) {  // empty list after deleting
    head_ = tail_ = nullptr;
  } else if (index == 0) {  // head node deleted
    head_ = prev->next;
  } else if (is_tail) {  // tail node deleted
    tail_ = prev;
  }
}

};  // namespace leetcode