#include "leetcode/problems/verify-preorder-serialization-of-a-binary-tree.h"

#include <sstream>

namespace leetcode {
namespace problem_331 {

namespace {

// Slot-counting method.
// Maintain a count of available subtree slots. Initially there is 1 slot (the
// root). For each token:
//   - if slots has dropped to 0 while tokens remain, it is malformed;
//   - a '#' consumes one slot;
//   - a value consumes one slot and adds two (its children).
// The result is valid iff at the end slots == 0 and slots never went negative.
bool isValidSerializationImpl(const std::string& preorder) {
  std::istringstream iss(preorder);
  std::string token;
  int slots = 1;
  while (std::getline(iss, token, ',')) {
    if (slots == 0) {
      return false;
    }
    if (token == "#") {
      --slots;
    } else {
      ++slots;
    }
  }
  return slots == 0;
}

}  // namespace

VerifyPreorderSerializationOfABinaryTreeSolution::
    VerifyPreorderSerializationOfABinaryTreeSolution() {
  setMetaInfo({.id = 331,
               .title = "Verify Preorder Serialization of a Binary Tree",
               .url = "https://leetcode.com/problems/verify-preorder-"
                      "serialization-of-a-binary-tree/"});
  registerStrategy(
      {.name = "SlotCounting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Stack", "Tree", "Binary Tree"}},
      isValidSerializationImpl);
}

bool VerifyPreorderSerializationOfABinaryTreeSolution::isValidSerialization(
    std::string preorder) {
  return getSolution()(std::move(preorder));
}

}  // namespace problem_331
}  // namespace leetcode
