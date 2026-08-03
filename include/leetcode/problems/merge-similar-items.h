#ifndef LEETCODE_PROBLEMS_MERGE_SIMILAR_ITEMS_H
#define LEETCODE_PROBLEMS_MERGE_SIMILAR_ITEMS_H

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2363 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class MergeSimilarItemsSolution : public SolutionBase<Func> {
 public:
  MergeSimilarItemsSolution();

  std::vector<std::vector<int>> mergeSimilarItems(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2);
};

}  // namespace problem_2363
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MERGE_SIMILAR_ITEMS_H
