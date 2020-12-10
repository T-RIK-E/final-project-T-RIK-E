//
// Created by rtera on 11/25/2020.
//

#pragma once
#include <core/sort.h>
#include <stack>

namespace sorting {
class QuickSort : public Sort {
 public:
  QuickSort();
  explicit QuickSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
  void ReInitialize() override;
 private:
  /**
   * Partition the array
   * @return If partition is complete, return true
   */
  bool partition();
  int high_, low_, pivot_;
  int i_, j_;
  bool partitioned_, go_;
  // Stack of the parameters instead of recursively calling
  std::stack<size_t> stack_;
};
} // namespace sorting