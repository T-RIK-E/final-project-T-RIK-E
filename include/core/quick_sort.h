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
 private:
  bool partition();
  int high_, low_, pivot_;
  int i_, j_;
  bool partitioned_, go_;
  std::stack<size_t> stack_;
};
}