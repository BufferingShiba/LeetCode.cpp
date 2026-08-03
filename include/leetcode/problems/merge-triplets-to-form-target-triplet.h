#ifndef LEETCODE_PROBLEMS_MERGE_TRIPLETS_TO_FORM_TARGET_TRIPLET_H
#define LEETCODE_PROBLEMS_MERGE_TRIPLETS_TO_FORM_TARGET_TRIPLET_H

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1899 {

using Func = std::function<bool(std::vector<std::vector<int>>&, std::vector<int>&)>;

class MergeTripletsToFormTargetTriplet : public SolutionBase<Func> {
 public:
  MergeTripletsToFormTargetTriplet();

  bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target);
};

}  // namespace problem_1899
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MERGE_TRIPLETS_TO_FORM_TARGET_TRIPLET_H
