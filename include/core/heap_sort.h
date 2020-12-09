//
// Created by rtera on 11/29/2020.
//

#pragma once
#include <core/sort.h>
#include <stack>

namespace sorting {
class HeapSort : public Sort {
 public:
  HeapSort();
  explicit HeapSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
  void ReInitialize() override;
 private:
  std::stack<size_t> stack_;
  size_t heap_size_, root_, largest_, index_;
  int i_, j_;
  bool Heapify();
};
}