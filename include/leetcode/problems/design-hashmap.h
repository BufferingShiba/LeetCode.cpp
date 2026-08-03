#ifndef LEETCODE_PROBLEMS_DESIGN_HASHMAP_H_
#define LEETCODE_PROBLEMS_DESIGN_HASHMAP_H_

#include <vector>

namespace problem_706 {

class DesignHashmap {
 public:
  DesignHashmap();
  void put(int key, int value);
  int get(int key);
  void remove(int key);

 private:
  std::vector<int> table_;
};

}  // namespace problem_706

#endif  // LEETCODE_PROBLEMS_DESIGN_HASHMAP_H_
