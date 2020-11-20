//
// Created by rtera on 11/19/2020.
//

#pragma once
#include <core/sort.h>
#include <vector>

namespace sorting {
class SelectionSort : public Sort {
 public:
  SelectionSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
 private:
  int i_, j_, min_idx_;
};
}