#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/remove-linked-list-elements.h"
#include "leetcode/utils/linked-list.h"

namespace leetcode {
namespace problem_203 {

using RemoveLinkedListElementsTest =
    ::testing::TestWithParam<std::string>;

class RemoveLinkedListElementsFixture : public RemoveLinkedListElementsTest {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveLinkedListElementsSolution solution;
};

TEST_P(RemoveLinkedListElementsFixture, Example1) {
  ListNode* head = constructLinkedList(std::vector<int>{1, 2, 6, 3, 4, 5, 6});
  ListNode* result = solution.removeElements(head, 6);
  EXPECT_EQ(traverse(result), std::vector<int>({1, 2, 3, 4, 5}));
}

TEST_P(RemoveLinkedListElementsFixture, Example2EmptyList) {
  ListNode* head = constructLinkedList(std::vector<int>{});
  ListNode* result = solution.removeElements(head, 1);
  EXPECT_EQ(traverse(result), std::vector<int>{});
}

TEST_P(RemoveLinkedListElementsFixture, Example3AllRemoved) {
  ListNode* head = constructLinkedList(std::vector<int>{7, 7, 7, 7});
  ListNode* result = solution.removeElements(head, 7);
  EXPECT_EQ(traverse(result), std::vector<int>{});
}

INSTANTIATE_TEST_SUITE_P(
    RemoveLinkedListElementsTestSuite, RemoveLinkedListElementsFixture,
    ::testing::ValuesIn(RemoveLinkedListElementsSolution().getStrategyNames()));

}  // namespace problem_203
}  // namespace leetcode
