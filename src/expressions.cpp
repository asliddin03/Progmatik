#include "expressions.hpp"

void Expressions::Print() {
  if (variants_[ans_] == 0) {
    for (int i = 0; i < ans_.size(); ++i) {
      if (ans_[i] >= 0 && i != 0) {
        std::cout << '+';
      }
      std::cout << ans_[i];
    }
    std::cout << "=200" << std::endl;
  }
  variants_[ans_] = 1;
}

void Expressions::Update() {
  sum_ = 0;
  last_ = 9;
  flag_ = false;
  ans_.clear();
}

void Expressions::Solve() {
  Update();
  for (int i = 8; i >= 0; --i) {
    if (arr_[8 - i] == 0) {
      last_ *= 10;
      last_ += i;
    } else if (arr_[8 - i] == 1) {
      sum_ += last_ * (flag_ ? -1 : 1);
      ans_.push_back(last_ * (flag_ ? -1 : 1));
      last_ = i;
      flag_ = false;
    } else {
      sum_ += last_ * (flag_ ? -1 : 1);
      ans_.push_back(last_ * (flag_ ? -1 : 1));
      last_ = i;
      flag_ = true;
    }
  }
  sum_ += last_ * (flag_ ? -1 : 1);
  ans_.push_back(last_ * (flag_ ? -1 : 1));
  if (sum_ == 200) {
    Print();
  }
  for (int i = size_ - 1; i >= 0; --i) {
    if (arr_[i] != 2) {
      ++arr_[i];
      for (int j = i + 1; j < size_; ++j) {
        arr_[j] = 0;
      }
      Solve();
      return;
    }
  }
}

int main() {
  Expressions expressions;
  expressions.Solve();
  return 0;
}