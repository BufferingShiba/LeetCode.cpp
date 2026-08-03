#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/remove-nth-node-from-end-of-list.h"

namespace leetcode {
namespace problem_19 {
namespace {

std::vector<int> listToVec(ListNode* head) {
  std::vector<int> res;
  while (head) {
    res.push_back(head->val);
    head = head->next;
  }
  return res;
}

void deleteList(ListNode* head) {
  while (head) {
    ListNode* tmp = head;
    head = head->next;
    delete tmp;
  }
}

}  // namespace

class RemoveNthNodeFromEndOfListTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  RemoveNthNodeFromEndOfListSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(RemoveNthNodeFromEndOfListTest, Example1) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3, 4, 5});
  ListNode* out = solution.removeNthFromEnd(head, 2);
  EXPECT_EQ(listToVec(out), (std::vector<int>{1, 2, 3, 5}));
  deleteList(out);
}

TEST_P(RemoveNthNodeFromEndOfListTest, Example2) {
  ListNode* head = constructLinkedList(std::vector<int>{1});
  ListNode* out = solution.removeNthFromEnd(head, 1);
  EXPECT_EQ(listToVec(out), (std::vector<int>{}));
  deleteList(out);
}

TEST_P(RemoveNthNodeFromEndOfListTest, Example3) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2});
  ListNode* out = solution.removeNthFromEnd(head, 1);
  EXPECT_EQ(listToVec(out), (std::vector<int>{1}));
  deleteList(out);
}

TEST_P(RemoveNthNodeFromEndOfListTest, SelfAuthoredRemoveHead) {
  // n == sz：删除头节点
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 3});
  ListNode* out = solution.removeNthFromEnd(head, 3);
  EXPECT_EQ(listToVec(out), (std::vector<int>{2, 3}));
  deleteList(out);
}

INSTANTIATE_TEST_SUITE_P(
    RemoveNthNodeFromEndOfListTestSuite, RemoveNthNodeFromEndOfListTest,
    testing::ValuesIn(RemoveNthNodeFromEndOfListSolution().getStrategyNames()));

}  // namespace problem_19
}  // namespace leetcode
