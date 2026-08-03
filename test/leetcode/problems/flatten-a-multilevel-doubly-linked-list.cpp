#include "leetcode/problems/flatten-a-multilevel-doubly-linked-list.h"

#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_430 {
namespace {

// Build a node with a given value (no links).
Node* makeNode(int v) { return new Node(v); }

// Serially link [a, b, ...]: a->next=b, b->prev=a.
void linkNext(Node* a, Node* b) {
  a->next = b;
  b->prev = a;
}

// Traverse the flattened list and return values as a vector.
std::vector<int> collect(Node* head) {
  std::vector<int> res;
  while (head != nullptr) {
    res.push_back(head->val);
    head = head->next;
  }
  return res;
}

void cleanup(Node* head) {
  Node* cur = head;
  while (cur != nullptr) {
    Node* next = cur->next;
    delete cur;
    cur = next;
  }
}

}  // namespace

class FlattenAMultilevelDoublyLinkedListTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FlattenAMultilevelDoublyLinkedListSolution solution_;
};

TEST_P(FlattenAMultilevelDoublyLinkedListTest, Example1) {
  // 1---2---3---4---5---6
  //         |
  //         7---8---9---10
  //             |
  //             11--12
  Node* n1 = makeNode(1);
  Node* n2 = makeNode(2);
  Node* n3 = makeNode(3);
  Node* n4 = makeNode(4);
  Node* n5 = makeNode(5);
  Node* n6 = makeNode(6);
  Node* n7 = makeNode(7);
  Node* n8 = makeNode(8);
  Node* n9 = makeNode(9);
  Node* n10 = makeNode(10);
  Node* n11 = makeNode(11);
  Node* n12 = makeNode(12);

  linkNext(n1, n2);
  linkNext(n2, n3);
  linkNext(n3, n4);
  linkNext(n4, n5);
  linkNext(n5, n6);
  linkNext(n7, n8);
  linkNext(n8, n9);
  linkNext(n9, n10);
  linkNext(n11, n12);

  n3->child = n7;
  n8->child = n11;

  Node* head = solution_.flatten(n1);

  std::vector<int> expected = {1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6};
  EXPECT_EQ(collect(head), expected);

  // Verify all child pointers are null and prev pointers consistent.
  for (Node* c = head; c != nullptr; c = c->next) {
    EXPECT_EQ(c->child, nullptr);
    if (c->prev != nullptr) {
      EXPECT_EQ(c->prev->next, c);
    }
  }

  cleanup(head);
}

TEST_P(FlattenAMultilevelDoublyLinkedListTest, Example2) {
  // 1---2
  // |
  // 3
  Node* n1 = makeNode(1);
  Node* n2 = makeNode(2);
  Node* n3 = makeNode(3);
  linkNext(n1, n2);
  n1->child = n3;

  Node* head = solution_.flatten(n1);

  EXPECT_EQ(collect(head), (std::vector<int>{1, 3, 2}));
  for (Node* c = head; c != nullptr; c = c->next) {
    EXPECT_EQ(c->child, nullptr);
  }

  cleanup(head);
}

TEST_P(FlattenAMultilevelDoublyLinkedListTest, Example3Empty) {
  EXPECT_EQ(solution_.flatten(nullptr), nullptr);
}

TEST_P(FlattenAMultilevelDoublyLinkedListTest, SelfAuthoredSingleNode) {
  Node* n1 = makeNode(1);
  Node* head = solution_.flatten(n1);
  EXPECT_EQ(collect(head), (std::vector<int>{1}));
  EXPECT_EQ(n1->child, nullptr);
  cleanup(head);
}

INSTANTIATE_TEST_SUITE_P(
    FlattenAMultilevelDoublyLinkedListTest,
    FlattenAMultilevelDoublyLinkedListTest,
    ::testing::ValuesIn(
        FlattenAMultilevelDoublyLinkedListSolution().getStrategyNames()));

}  // namespace problem_430
}  // namespace leetcode
