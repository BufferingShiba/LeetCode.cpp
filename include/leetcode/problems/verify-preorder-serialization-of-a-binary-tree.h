#ifndef LEETCODE_PROBLEMS_VERIFY_PREORDER_SERIALIZATION_OF_A_BINARY_TREE_H_
#define LEETCODE_PROBLEMS_VERIFY_PREORDER_SERIALIZATION_OF_A_BINARY_TREE_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_331 {

using Func = std::function<bool(std::string)>;

class VerifyPreorderSerializationOfABinaryTreeSolution
    : public SolutionBase<Func> {
 public:
  VerifyPreorderSerializationOfABinaryTreeSolution();

  bool isValidSerialization(std::string preorder);
};

}  // namespace problem_331
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VERIFY_PREORDER_SERIALIZATION_OF_A_BINARY_TREE_H_
