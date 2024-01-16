#include <iostream>
#include <map>
#include <vector>

class Expressions{
 public:
  void Update();
  void Solve();
 private:
  void Print();

  int sum_;
  int last_;
  bool flag_;
  int size_ = 9;
  std::vector<int> ans_;
  std::vector<int> arr_{0, 0, 0, 0, 0, 0, 0, 0, 0};
  std::map<std::vector<int>, int> variants_;
};