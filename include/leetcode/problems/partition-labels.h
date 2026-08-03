#ifndef LEETCODE_PROBLEM_PARTITION_LABELS_H_
#define LEETCODE_PROBLEM_PARTITION_LABELS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_763 {

using Func = std::function<std::vector<int>(std::string)>;

class PartitionLabelsSolution : public SolutionBase<Func> {
 public:
  PartitionLabelsSolution();

  std::vector<int> partitionLabels(std::string s);
};

}  // namespace problem_763
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_PARTITION_LABELS_H_
