#ifndef LEETCODE_PROBLEMS_MOST_POPULAR_VIDEO_CREATOR_H_
#define LEETCODE_PROBLEMS_MOST_POPULAR_VIDEO_CREATOR_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2456 {

using Func = std::function<std::vector<std::vector<std::string>>(
    std::vector<std::string>&, std::vector<std::string>&, std::vector<int>&)>;

class MostPopularVideoCreatorSolution : public SolutionBase<Func> {
 public:
  MostPopularVideoCreatorSolution() {
    setMetaInfo({.id = 2456,
                 .title = "Most Popular Video Creator",
                 .url = "https://leetcode.com/problems/most-popular-video-creator/"});
    registerStrategy(
        {.name = "hashmap", .expected = "Accepted", .time_complexity = "O(n)",
         .space_complexity = "O(n)", .tags = {"Array", "Hash Table"}},
        mostPopularCreatorImpl);
  }

  std::vector<std::vector<std::string>> mostPopularCreator(
      std::vector<std::string>& creators, std::vector<std::string>& ids,
      std::vector<int>& views) {
    return getSolution()(creators, ids, views);
  }

 private:
  static std::vector<std::vector<std::string>> mostPopularCreatorImpl(
      std::vector<std::string>& creators, std::vector<std::string>& ids,
      std::vector<int>& views) {
    std::unordered_map<std::string, long long> popularity;
    std::unordered_map<std::string, std::string> bestId;
    std::unordered_map<std::string, long long> bestViews;

    for (size_t i = 0; i < creators.size(); ++i) {
      const std::string& creator = creators[i];
      const std::string& id = ids[i];
      long long v = views[i];

      popularity[creator] += v;

      auto it = bestViews.find(creator);
      if (it == bestViews.end() || v > it->second ||
          (v == it->second && id < bestId[creator])) {
        bestViews[creator] = v;
        bestId[creator] = id;
      }
    }

    long long maxPop = -1;
    for (const auto& [creator, pop] : popularity) {
      maxPop = std::max(maxPop, pop);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& [creator, pop] : popularity) {
      if (pop == maxPop) {
        result.push_back({creator, bestId[creator]});
      }
    }
    return result;
  }
};

}  // namespace problem_2456
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MOST_POPULAR_VIDEO_CREATOR_H_
