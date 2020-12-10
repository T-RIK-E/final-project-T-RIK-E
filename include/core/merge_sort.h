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
  // queue of indicies of the sub arrays that need to be sorted
  std::queue<size_t> indexes_;
  bool sorted_;
  // Sub arrays to be sorted
  vector<size_t> left_, right_;
  size_t i_, j_, k_;

  /**
   * Merge two sorted subarrays into one larger sorted array
   */
  void Merge();

  /**
   * Split larger unsorted array into smaller unsorteed array
   */
  void SplitArray();
};
}  // namespace sorting
