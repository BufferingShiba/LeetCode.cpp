#include "leetcode/problems/design-bitset.h"

namespace leetcode {
namespace problem_2166 {

Bitset::Bitset(int size)
    : size_(size), ones_(0), flipped_(false), data_(size, 0) {}

void Bitset::fix(int idx) {
  unsigned char actual = data_[idx] ^ flipped_;
  if (actual == 0) {
    data_[idx] = static_cast<unsigned char>(1 ^ flipped_);
    ++ones_;
  }
}

void Bitset::unfix(int idx) {
  unsigned char actual = data_[idx] ^ flipped_;
  if (actual == 1) {
    data_[idx] = static_cast<unsigned char>(0 ^ flipped_);
    --ones_;
  }
}

void Bitset::flip() {
  flipped_ = !flipped_;
  ones_ = size_ - ones_;
}

bool Bitset::all() { return ones_ == size_; }

bool Bitset::one() { return ones_ > 0; }

int Bitset::count() { return ones_; }

std::string Bitset::toString() {
  std::string s;
  s.reserve(size_);
  for (int i = 0; i < size_; ++i) {
    s.push_back(static_cast<char>('0' + (data_[i] ^ flipped_)));
  }
  return s;
}

}  // namespace problem_2166
}  // namespace leetcode
