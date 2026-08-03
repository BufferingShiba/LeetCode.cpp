#ifndef LEETCODE_PROBLEMS_DESIGN_LINKED_LIST_H__
#define LEETCODE_PROBLEMS_DESIGN_LINKED_LIST_H__

namespace problem_707 {

//! A singly linked list implementation supporting 0-indexed operations.
class MyLinkedList {
 public:
  MyLinkedList();
  ~MyLinkedList();

  // Returns the value of the index-th node, or -1 if invalid.
  int get(int index);

  // Adds a node before the first element.
  void addAtHead(int val);

  // Appends a node as the last element.
  void addAtTail(int val);

  // Adds a node before the index-th node. If index == size_, appends to end;
  // if index > size_, it is not inserted.
  void addAtIndex(int index, int val);

  // Deletes the index-th node if the index is valid.
  void deleteAtIndex(int index);

 private:
  struct Node {
    int val;
    Node* next;
    Node(int v, Node* n = nullptr) : val(v), next(n) {}
  };

  Node* dummy_;  // sentinel head node (its value is unused)
  int size_;
};

}  // namespace problem_707

#endif  // LEETCODE_PROBLEMS_DESIGN_LINKED_LIST_H__
