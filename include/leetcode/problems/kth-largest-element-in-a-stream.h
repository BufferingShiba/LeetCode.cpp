#ifndef LEETCODE_PROBLEMS_KTH_LARGEST_ELEMENT_IN_A_STREAM_H__
#define LEETCODE_PROBLEMS_KTH_LARGEST_ELEMENT_IN_A_STREAM_H__

#include <queue>
#include <vector>

namespace problem_703 {

// KthLargest: maintains the kth largest element of a stream in real time.
class KthLargest {
 public:
  KthLargest(int k, const std::vector<int>& nums) : k_(k) {
    for (int num : nums) {
      add(num);
    }
  }

  int add(int val) {
    pq_.push(val);
    if (static_cast<int>(pq_.size()) > k_) {
      pq_.pop();
    }
    return pq_.top();
  }

 private:
  int k_;
  // Min-heap keeping only the k largest elements seen so far.
  // Its top (smallest among the kept) is the kth largest overall.
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq_;
};

}  // namespace problem_703

#endif  // LEETCODE_PROBLEMS_KTH_LARGEST_ELEMENT_IN_A_STREAM_H__
