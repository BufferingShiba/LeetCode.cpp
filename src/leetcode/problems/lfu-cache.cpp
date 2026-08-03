#include "leetcode/problems/lfu-cache.h"

namespace leetcode {
namespace problem_460 {

LFUCache::LFUCache(int capacity)
    : capacity_(capacity), minFreq_(0) {}

int LFUCache::get(int key) {
  auto it = keyToIter_.find(key);
  if (it == keyToIter_.end()) {
    return -1;
  }
  auto listIter = it->second;
  int value = listIter->value;
  int freq = listIter->freq;

  // Access freq+1 first: may insert a new empty list (potential rehash).
  // Then access old list (guaranteed to exist).
  auto& newList = freqToList_[freq + 1];
  auto& oldList = freqToList_[freq];
  newList.splice(newList.begin(), oldList, listIter);
  listIter->freq = freq + 1;

  if (oldList.empty() && minFreq_ == freq) {
    ++minFreq_;
  }

  return value;
}

void LFUCache::put(int key, int value) {
  if (capacity_ == 0) {
    return;
  }

  auto it = keyToIter_.find(key);
  if (it != keyToIter_.end()) {
    // Update existing key.
    auto listIter = it->second;
    listIter->value = value;
    int freq = listIter->freq;

    auto& newList = freqToList_[freq + 1];
    auto& oldList = freqToList_[freq];
    newList.splice(newList.begin(), oldList, listIter);
    listIter->freq = freq + 1;

    if (oldList.empty() && minFreq_ == freq) {
      ++minFreq_;
    }
    return;
  }

  // Evict LFU (with LRU tiebreak) if capacity reached.
  if (static_cast<int>(keyToIter_.size()) == capacity_) {
    auto& oldList = freqToList_[minFreq_];
    auto evictIter = std::prev(oldList.end());
    int evictKey = evictIter->key;
    oldList.erase(evictIter);
    keyToIter_.erase(evictKey);
  }

  // Insert new key with freq = 1.
  freqToList_[1].push_front({key, value, 1});
  keyToIter_[key] = freqToList_[1].begin();
  minFreq_ = 1;
}

}  // namespace problem_460
}  // namespace leetcode
