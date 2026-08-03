#ifndef LEETCODE_PROBLEMS_DECOMPRESS_RUN_LENGTH_ENCODED_LIST_H__
#define LEETCODE_PROBLEMS_DECOMPRESS_RUN_LENGTH_ENCODED_LIST_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1313 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class DecompressRunLengthEncodedListSolution : public SolutionBase<Func> {
 public:
  DecompressRunLengthEncodedListSolution();

  std::vector<int> decompressRLElist(std::vector<int>& nums);
};

}  // namespace problem_1313
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DECOMPRESS_RUN_LENGTH_ENCODED_LIST_H__
