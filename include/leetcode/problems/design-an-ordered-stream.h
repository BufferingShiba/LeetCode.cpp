#ifndef LEETCODE_PROBLEMS_DESIGN_AN_ORDERED_STREAM_H__
#define LEETCODE_PROBLEMS_DESIGN_AN_ORDERED_STREAM_H__

#include <string>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_1656 {

class OrderedStream {
 public:
  explicit OrderedStream(int n);

  std::vector<std::string> insert(int idKey, std::string value);

 private:
  std::vector<std::string> stream_;
  int ptr_;
};

using DesignAnOrderedStreamSolution = OrderedStream;

}  // namespace problem_1656
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DESIGN_AN_ORDERED_STREAM_H__
