#ifndef LEETCODE_PROBLEM_2478_H_
#define LEETCODE_PROBLEM_2478_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2478 {

using Func = std::function<int(const std::string&, int, int)>;

class NumberOfBeautifulPartitionsSolution : public SolutionBase<Func> {
 public:
  NumberOfBeautifulPartitionsSolution();

  int beautifulPartitions(const std::string& s, int k, int minLength);
};

}  // namespace problem_2478
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2478_H_
