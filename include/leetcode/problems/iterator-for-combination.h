#ifndef LEETCODE_PROBLEMS_ITERATOR_FOR_COMBINATION_H__
#define LEETCODE_PROBLEMS_ITERATOR_FOR_COMBINATION_H__

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1286 {

class CombinationIterator {
 public:
  CombinationIterator(std::string characters, int combinationLength);
  std::string next();
  bool hasNext();

 private:
  void generate(const std::string& characters, int idx, int remaining,
                std::string& cur);

  std::vector<std::string> combinations_;
  size_t pos_ = 0;
};

}  // namespace problem_1286
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ITERATOR_FOR_COMBINATION_H__
