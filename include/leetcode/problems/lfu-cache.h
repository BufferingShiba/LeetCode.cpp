#ifndef LEETCODE_PROBLEMS_LFU_CACHE_H_
#define LEETCODE_PROBLEMS_LFU_CACHE_H_

#include <list>
#include <unordered_map>

namespace leetcode {
namespace problem_460 {

class LFUCache {
 private:
  struct Node {
    int key;
    int value;
    int freq;
  };

  int capacity_;
  int minFreq_;
  std::unordered_map<int, std::list<Node>::iterator> keyToIter_;
  std::unordered_map<int, std::list<Node>> freqToList_;

 public:
  explicit LFUCache(int capacity);
  int get(int key);
  void put(int key, int value);
};

}  // namespace problem_460
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LFU_CACHE_H_
