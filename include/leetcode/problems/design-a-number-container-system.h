#ifndef LEETCODE_PROBLEMS_DESIGN_A_NUMBER_CONTAINER_SYSTEM_H_
#define LEETCODE_PROBLEMS_DESIGN_A_NUMBER_CONTAINER_SYSTEM_H_

#include <set>
#include <unordered_map>

namespace leetcode {
namespace problem_2349 {

class NumberContainers {
 public:
  NumberContainers();
  void change(int index, int number);
  int find(int number);

 private:
  std::unordered_map<int, int> idx_to_num_;
  std::unordered_map<int, std::set<int>> num_to_indices_;
};

}  // namespace problem_2349
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DESIGN_A_NUMBER_CONTAINER_SYSTEM_H_
