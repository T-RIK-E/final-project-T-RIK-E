//
// Created by rtera on 11/19/2020.
//

#pragma once
#include <core/sort.h>

namespace sorting {
class SelectionSort : public Sort {
 public:
  SelectionSort();
  explicit SelectionSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
  void ReInitialize() override;
 private:
  int i_, j_, min_idx_;
};
}