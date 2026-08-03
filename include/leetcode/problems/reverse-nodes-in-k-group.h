#ifndef LEETCODE_PROBLEMS_REVERSE_NODES_IN_K_GROUP_H__
#define LEETCODE_PROBLEMS_REVERSE_NODES_IN_K_GROUP_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/utils/linked-list.h"

namespace leetcode {
namespace problem_25 {

using Func = std::function<leetcode::ListNode*(leetcode::ListNode*, int)>;

class ReverseNodesInKGroupSolution : public SolutionBase<Func> {
 public:
  ReverseNodesInKGroupSolution();

  leetcode::ListNode* reverseKGroup(leetcode::ListNode* head, int k);

  [[nodiscard]] std::vector<std::string> getStrategyNames() const {
    return SolutionBase::getStrategyNames();
  }

  void setStrategy(const std::string& name) {
    SolutionBase::setStrategy(name);
  }
};

}  // namespace problem_25
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REVERSE_NODES_IN_K_GROUP_H__
