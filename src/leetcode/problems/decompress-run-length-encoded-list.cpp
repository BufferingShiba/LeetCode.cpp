#include "leetcode/problems/decompress-run-length-encoded-list.h"

#include <vector>

namespace leetcode {
namespace problem_1313 {
namespace {

std::vector<int> decompressRLElistImpl(std::vector<int>& nums) {
  std::vector<int> result;
  for (std::size_t i = 0; i + 1 < nums.size(); i += 2) {
    int freq = nums[i];
    int val = nums[i + 1];
    result.insert(result.end(), freq, val);
  }
  return result;
}

}  // namespace

DecompressRunLengthEncodedListSolution::DecompressRunLengthEncodedListSolution() {
  setMetaInfo({1313, "Decompress Run-Length Encoded List",
               "https://leetcode.com/problems/decompress-run-length-encoded-list/"});
  registerStrategy(
      {"SinglePass", "Accepted", "O(n + m)", "O(m)", {"Array"},
       "Iterate adjacent pairs [freq, val] and append freq copies of val."},
      decompressRLElistImpl);
}

std::vector<int> DecompressRunLengthEncodedListSolution::decompressRLElist(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1313
}  // namespace leetcode
