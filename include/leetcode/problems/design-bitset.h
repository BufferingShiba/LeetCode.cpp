#ifndef LEETCODE_PROBLEMS_DESIGN_BITSET_H__
#define LEETCODE_PROBLEMS_DESIGN_BITSET_H__

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2166 {

class Bitset {
 public:
  Bitset(int size);

  void fix(int idx);
  void unfix(int idx);
  void flip();
  bool all();
  bool one();
  int count();
  std::string toString();

 private:
  int size_;
  int ones_;
  bool flipped_;
  std::vector<unsigned char> data_;
};

}  // namespace problem_2166
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DESIGN_BITSET_H__
