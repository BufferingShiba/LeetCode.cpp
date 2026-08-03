#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/design-linked-list.h"

namespace problem_707 {

class DesignLinkedListTest : public ::testing::TestWithParam<int> {
 protected:
  // Runs a scripted sequence of operations on a fresh MyLinkedList.
  // Methods: 0=get, 1=addAtHead, 2=addAtTail, 3=addAtIndex, 4=deleteAtIndex
  void Run(const std::vector<std::vector<int>>& ops) {
    MyLinkedList list;
    for (const auto& op : ops) {
      int method = op[0];
      switch (method) {
        case 0:
          EXPECT_EQ(op[2], list.get(op[1]));
          break;
        case 1:
          list.addAtHead(op[1]);
          break;
        case 2:
          list.addAtTail(op[1]);
          break;
        case 3:
          list.addAtIndex(op[1], op[2]);
          break;
        case 4:
          list.deleteAtIndex(op[1]);
          break;
      }
    }
  }
};

TEST_P(DesignLinkedListTest, OfficialExample) {
  // addAtHead(1); addAtTail(3); addAtIndex(1,2); get(1)==2;
  // deleteAtIndex(1); get(1)==3
  Run({{1, 1},
       {2, 3},
       {3, 1, 2},
       {0, 1, 2},
       {4, 1},
       {0, 1, 3}});
}

TEST_P(DesignLinkedListTest, SelfAuthoredHeadTailEdgeCases) {
  // addAtHead(1); addAtHead(2); get(0)==2; addAtTail(3); get(2)==3
  Run({{1, 1},
       {1, 2},
       {0, 0, 2},
       {2, 3},
       {0, 2, 3}});
}

TEST_P(DesignLinkedListTest, SelfAuthoredInvalidIndexOperations) {
  // get on empty/out-of-range returns -1; delete invalid index is ignored
  Run({{0, 0, -1},
       {1, 5},
       {0, 1, -1},
       {4, 5},
       {0, 0, 5}});
}

TEST_P(DesignLinkedListTest, SelfAuthoredAddAtIndexBounds) {
  // addAtIndex(0,1); addAtIndex(2,2) (index>size -> ignored);
  // addAtIndex(size,3) appends to tail
  Run({{3, 0, 1},
       {3, 2, 2},
       {0, 0, 1},
       {3, 1, 3},
       {0, 1, 3}});
}

TEST_P(DesignLinkedListTest, SelfAuthoredDeleteHeadAndTail) {
  // addAtHead(1); addAtTail(2); addAtTail(3); deleteAtIndex(0); get(0)==2;
  // deleteAtIndex(1); get(0)==2
  Run({{1, 1},
       {2, 2},
       {2, 3},
       {4, 0},
       {0, 0, 2},
       {4, 1},
       {0, 0, 2}});
}

INSTANTIATE_TEST_SUITE_P(DesignLinkedListTestSuite, DesignLinkedListTest,
                         ::testing::Values(0));

}  // namespace problem_707
