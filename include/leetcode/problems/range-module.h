#ifndef LEETCODE_PROBLEMS_RANGE_MODULE_H__
#define LEETCODE_PROBLEMS_RANGE_MODULE_H__

#include <map>

namespace leetcode {
namespace problem_715 {

class RangeModule {
 public:
  RangeModule() = default;

  void addRange(int left, int right);
  bool queryRange(int left, int right);
  void removeRange(int left, int right);

 private:
  // Ordered disjoint intervals [key, value).
  std::map<int, int> ranges_;
};

}  // namespace problem_715
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RANGE_MODULE_H__
