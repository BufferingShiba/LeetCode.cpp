#include "leetcode/problems/iterator-for-combination.h"

namespace leetcode {
namespace problem_1286 {

CombinationIterator::CombinationIterator(std::string characters,
                                         int combinationLength) {
  std::string cur;
  generate(characters, 0, combinationLength, cur);
}

std::string CombinationIterator::next() { return combinations_[pos_++]; }

bool CombinationIterator::hasNext() { return pos_ < combinations_.size(); }

void CombinationIterator::generate(const std::string& characters, int idx,
                                   int remaining, std::string& cur) {
  if (remaining == 0) {
    combinations_.push_back(cur);
    return;
  }
  for (int i = idx; i + remaining <= static_cast<int>(characters.size()); ++i) {
    cur.push_back(characters[i]);
    generate(characters, i + 1, remaining - 1, cur);
    cur.pop_back();
  }
}

}  // namespace problem_1286
}  // namespace leetcode
