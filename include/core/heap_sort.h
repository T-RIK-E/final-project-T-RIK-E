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
  // Stack of parameters for every recursive operation
  std::stack<size_t> stack_;
  // Variables we need to keep track of
  size_t heap_size_, root_, largest_, index_;
  int i_, j_;

  /**
   * Creates the heap of a given sub tree
   * @return Whether or not the heap has finished creating
   */
  bool Heapify();
};
} // namespace sorting