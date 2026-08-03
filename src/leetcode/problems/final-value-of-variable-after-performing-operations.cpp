#include "leetcode/problems/final-value-of-variable-after-performing-operations.h"

namespace leetcode {
namespace problem_2011 {

namespace {

int finalValueAfterOperationsImpl(std::vector<std::string>& operations) {
  int x = 0;
  for (const std::string& op : operations) {
    if (op.find('+') != std::string::npos) {
      ++x;
    } else {
      --x;
    }
  }
  return x;
}

}  // namespace

FinalValueOfVariableAfterPerformingOperationsSolution::
    FinalValueOfVariableAfterPerformingOperationsSolution() {
  setMetaInfo({.id = 2011,
               .title = "Final Value of Variable After Performing Operations",
               .url = "https://leetcode.com/problems/final-value-of-variable-after-performing-operations/"});
  registerStrategy(
      {"simulation",
       "Accepted",
       "O(n)",
       "O(1)",
       {"Array", "String", "Simulation"}},
      finalValueAfterOperationsImpl);
}

int FinalValueOfVariableAfterPerformingOperationsSolution::finalValueAfterOperations(
    std::vector<std::string>& operations) {
  return getSolution()(operations);
}

}  // namespace problem_2011
}  // namespace leetcode
