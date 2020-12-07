//
// Created by rtera on 11/29/2020.
//

#pragma once
#include <core/sort.h>
namespace sorting {
class CountingSort : public Sort {
 public:
  CountingSort();
  explicit CountingSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
 private:
  std::vector<size_t> count_;
  std::vector<size_t> output_;
  size_t max_;
  int i_, j_, k_, l_, m_;
};
}