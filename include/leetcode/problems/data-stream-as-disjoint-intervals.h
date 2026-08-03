#ifndef LEETCODE_PROBLEM_352_DATA_STREAM_AS_DISJOINT_INTERVALS_H_
#define LEETCODE_PROBLEM_352_DATA_STREAM_AS_DISJOINT_INTERVALS_H_

#include <vector>
#include <map>

namespace leetcode {
namespace problem_352 {

class SummaryRanges {
public:
    SummaryRanges();
    void addNum(int value);
    std::vector<std::vector<int>> getIntervals();

private:
    std::map<int, int> intervals_; // start -> end
};

} // namespace problem_352
} // namespace leetcode

#endif
