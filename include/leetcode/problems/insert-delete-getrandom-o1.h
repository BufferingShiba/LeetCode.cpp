#ifndef LEETCODE_PROBLEMS_INSERT_DELETE_GETRANDOM_O1_H
#define LEETCODE_PROBLEMS_INSERT_DELETE_GETRANDOM_O1_H

#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_380 {

class RandomizedSet {
 public:
  RandomizedSet();
  bool insert(int val);
  bool remove(int val);
  int getRandom();

 private:
  std::unordered_map<int, int> valToIndex_;
  std::vector<int> nums_;
};

}  // namespace problem_380
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INSERT_DELETE_GETRANDOM_O1_H
