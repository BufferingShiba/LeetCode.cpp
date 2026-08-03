#ifndef LEETCODE_PROBLEMS_DESTINATION_CITY_H_
#define LEETCODE_PROBLEMS_DESTINATION_CITY_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1436 {

using Func = std::function<std::string(std::vector<std::vector<std::string>>&)>;

class DestinationCitySolution : public SolutionBase<Func> {
 public:
  DestinationCitySolution();

  std::string destCity(std::vector<std::vector<std::string>>& paths);
};

}  // namespace problem_1436
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DESTINATION_CITY_H_
