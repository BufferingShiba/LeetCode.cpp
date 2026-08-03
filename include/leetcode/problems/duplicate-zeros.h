#ifndef LEETCODE_PROBLEMS_DUPLICATE_ZEROS_H__
#define LEETCODE_PROBLEMS_DUPLICATE_ZEROS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1089 {

using Func = std::function<void(std::vector<int>&)>;

class DuplicateZerosSolution : public SolutionBase<Func> {
 public:
  void duplicateZeros(std::vector<int>& arr);

  DuplicateZerosSolution() {
    setMetaInfo({1089, "Duplicate Zeros", "https://leetcode.com/problems/duplicate-zeros/"});
    registerStrategy();
  }

 private:
  void registerStrategy();
};

}  // namespace problem_1089
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DUPLICATE_ZEROS_H__
