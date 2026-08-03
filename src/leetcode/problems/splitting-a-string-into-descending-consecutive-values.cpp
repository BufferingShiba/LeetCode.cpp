#include "leetcode/problems/splitting-a-string-into-descending-consecutive-values.h"

#include <cstddef>
#include <string>
#include <unordered_set>
#include <utility>

namespace leetcode {
namespace problem_1849 {

namespace {

using State = std::pair<std::size_t, std::string>;

struct StateHash {
  std::size_t operator()(const State& s) const noexcept {
    return std::hash<std::size_t>{}(s.first) ^
           (std::hash<std::string>{}(s.second) << 1);
  }
};

std::string normalize(const std::string& value) {
  const std::size_t first = value.find_first_not_of('0');
  return first == std::string::npos ? "0" : value.substr(first);
}

int compareNumbers(const std::string& lhs, const std::string& rhs) {
  if (lhs.size() != rhs.size()) {
    return lhs.size() < rhs.size() ? -1 : 1;
  }
  if (lhs == rhs) return 0;
  return lhs < rhs ? -1 : 1;
}

std::string decrement(const std::string& value) {
  std::string result = value;
  for (std::size_t i = result.size(); i-- > 0;) {
    if (result[i] == '0') {
      result[i] = '9';
    } else {
      --result[i];
      break;
    }
  }
  return normalize(result);
}

class Solver {
 public:
  explicit Solver(const std::string& s) : s_(s), n_(s.size()) {}

  bool run() {
    if (n_ < 2) {
      return false;
    }
    std::string first;
    for (std::size_t k = 1; k < n_; ++k) {
      first = normalize(s_.substr(0, k));
      visited_.clear();
      if (dfs(k, first)) {
        return true;
      }
    }
    return false;
  }

 private:
  bool dfs(std::size_t start, const std::string& prev) {
    if (start == n_) {
      return true;
    }
    State key(start, prev);
    if (visited_.count(key)) {
      return false;
    }
    visited_.insert(key);

    if (prev == "0") {
      return false;
    }
    const std::string target = decrement(prev);
    for (std::size_t i = start; i < n_; ++i) {
      const std::string value = normalize(s_.substr(start, i - start + 1));
      const int comparison = compareNumbers(value, target);
      if (comparison > 0) {
        break;
      }
      if (comparison == 0 && dfs(i + 1, value)) {
        return true;
      }
    }
    return false;
  }

  const std::string& s_;
  const std::size_t n_;
  std::unordered_set<State, StateHash> visited_;
};

bool splitStringImpl(const std::string& s) {
  return Solver(s).run();
}

}  // namespace

SplittingAStringIntoDescendingConsecutiveValuesSolution::
    SplittingAStringIntoDescendingConsecutiveValuesSolution() {
  setMetaInfo({.id = 1849,
               .title = "Splitting a String Into Descending Consecutive Values",
               .url = "https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/"});
  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(2^n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Backtracking", "Enumeration"}},
      splitStringImpl);
}

bool SplittingAStringIntoDescendingConsecutiveValuesSolution::splitString(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1849
}  // namespace leetcode
