#include "leetcode/problems/design-browser-history.h"

#include <algorithm>
#include <utility>

namespace leetcode {
namespace problem_1472 {

BrowserHistory::BrowserHistory(std::string homepage)
    : cur_(0), sz_(0) {
  history_.push_back(std::move(homepage));
}

void BrowserHistory::visit(std::string url) {
  ++cur_;
  if (cur_ == static_cast<int>(history_.size())) {
    history_.push_back(std::move(url));
  } else {
    history_[cur_] = std::move(url);
  }
  sz_ = cur_;
}

std::string BrowserHistory::back(int steps) {
  cur_ = std::max(0, cur_ - steps);
  return history_[cur_];
}

std::string BrowserHistory::forward(int steps) {
  cur_ = std::min(sz_, cur_ + steps);
  return history_[cur_];
}

}  // namespace problem_1472
}  // namespace leetcode
