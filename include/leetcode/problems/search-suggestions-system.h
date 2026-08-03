#ifndef LEETCODE_PROBLEMS_1268_SEARCH_SUGGESTIONS_SYSTEM_H_
#define LEETCODE_PROBLEMS_1268_SEARCH_SUGGESTIONS_SYSTEM_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1268 {

using Func = std::function<std::vector<std::vector<std::string>>(
    std::vector<std::string>&, std::string)>;

class SearchSuggestionsSystemSolution : public SolutionBase<Func> {
 public:
  SearchSuggestionsSystemSolution();

  std::vector<std::vector<std::string>> suggestedProducts(
      std::vector<std::string>& products, std::string searchWord) {
    return getSolution()(products, std::move(searchWord));
  }
};

}  // namespace problem_1268
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_1268_SEARCH_SUGGESTIONS_SYSTEM_H_
