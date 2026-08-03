#include <gtest/gtest.h>

#include "leetcode/problems/intersection-of-two-linked-lists.h"

namespace leetcode {
namespace problem_160 {

class IntersectionOfTwoLinkedListsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  IntersectionOfTwoLinkedListsSolution solution;
};

TEST_P(IntersectionOfTwoLinkedListsTest, Example1) {
  // intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
  // skipA = 2, skipB = 3
  auto shared = constructLinkedList(std::vector<int>{8, 4, 5});
  auto prefixA = constructLinkedList(std::vector<int>{4, 1});
  auto prefixB = constructLinkedList(std::vector<int>{5, 6, 1});

  // Save original tail nodes before linking
  ListNode* tailA = getTail(prefixA);
  ListNode* tailB = getTail(prefixB);

  tailA->next = shared;
  tailB->next = shared;

  ListNode* result = solution.getIntersectionNode(prefixA, prefixB);
  EXPECT_EQ(result, shared);

  // Detach using saved tails, then each list is independent
  tailA->next = nullptr;
  tailB->next = nullptr;
  MyLinkedList cleanupA(prefixA);
  MyLinkedList cleanupB(prefixB);
  MyLinkedList cleanupShared(shared);
}

TEST_P(IntersectionOfTwoLinkedListsTest, Example2) {
  // intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4]
  // skipA = 3, skipB = 1
  auto shared = constructLinkedList(std::vector<int>{2, 4});
  auto prefixA = constructLinkedList(std::vector<int>{1, 9, 1});
  auto prefixB = constructLinkedList(std::vector<int>{3});

  ListNode* tailA = getTail(prefixA);
  ListNode* tailB = getTail(prefixB);

  tailA->next = shared;
  tailB->next = shared;

  ListNode* result = solution.getIntersectionNode(prefixA, prefixB);
  EXPECT_EQ(result, shared);

  tailA->next = nullptr;
  tailB->next = nullptr;
  MyLinkedList cleanupA(prefixA);
  MyLinkedList cleanupB(prefixB);
  MyLinkedList cleanupShared(shared);
}

TEST_P(IntersectionOfTwoLinkedListsTest, Example3) {
  // intersectVal = 0, listA = [2,6,4], listB = [1,5] — no intersection
  auto listA = constructLinkedList(std::vector<int>{2, 6, 4});
  auto listB = constructLinkedList(std::vector<int>{1, 5});

  ListNode* result = solution.getIntersectionNode(listA, listB);
  EXPECT_EQ(result, nullptr);

  MyLinkedList cleanupA(listA);
  MyLinkedList cleanupB(listB);
}

TEST_P(IntersectionOfTwoLinkedListsTest, SameList) {
  // Both heads point to the exact same list → intersection at head
  auto shared = constructLinkedList(std::vector<int>{1, 2, 3});

  ListNode* result = solution.getIntersectionNode(shared, shared);
  EXPECT_EQ(result, shared);

  MyLinkedList cleanup(shared);
}

INSTANTIATE_TEST_SUITE_P(
    IntersectionOfTwoLinkedListsTests,
    IntersectionOfTwoLinkedListsTest,
    testing::ValuesIn(
        IntersectionOfTwoLinkedListsSolution().getStrategyNames()));

}  // namespace problem_160
}  // namespace leetcode
