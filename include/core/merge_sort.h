//
// Created by rtera on 11/26/2020.
//

#pragma once
#include <core/sort.h>

#include <queue>

using std::vector;
namespace sorting {
class MergeSort : public Sort {
 public:
  MergeSort();
  explicit MergeSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
  void ReInitialize() override;
 private:
  std::queue<size_t> indexes_;
  bool sorted_;
  vector<size_t> left_, right_;
  size_t i_, j_, k_;
  void Merge();
  void SplitArray();
};
}  // namespace sorting
