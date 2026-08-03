#include "leetcode/problems/linked-list-components.h"

#include <unordered_set>

namespace leetcode {
namespace problem_817 {

namespace {

int numComponentsImpl(ListNode* head, std::vector<int>& nums) {
  std::unordered_set<int> in_nums(nums.begin(), nums.end());
  int count = 0;
  bool prev_in = false;
  for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
    bool cur_in = in_nums.count(cur->val) > 0;
    if (cur_in && !prev_in) {
      ++count;
    }
    prev_in = cur_in;
  }
  return count;
}

}  // namespace

int LinkedListComponentsSolution::numComponents(ListNode* head,
                                                std::vector<int>& nums) {
  return getSolution()(head, nums);
}

LinkedListComponentsSolution::LinkedListComponentsSolution() {
  setMetaInfo({
      817,
      "Linked List Components",
      "<https://leetcode.com/problems/linked-list-components/>",
  });
  registerStrategy(
      {
          "hash-set-scan",
          "Accepted",
          "O(n)",
          "O(m)",
          {"Array", "Hash Table", "Linked List"},
      },
      numComponentsImpl);
}

}  // namespace problem_817
}  // namespace leetcode
