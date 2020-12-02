//
// Created by rtera on 11/30/2020.
//

#pragma once
#include <core/sort.h>

namespace sorting {
class ShellSort : public Sort {
 public:
  ShellSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
 private:
  int gap_, i_, j_;
  int UpperBound(size_t num);
};
}