//
// Created by rtera on 11/15/2020.
//
#pragma once
#include <core/sort.h>

namespace sorting {
class InsertionSort : public Sort{
 public:
  explicit InsertionSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
 private:
  int i_, key_, j_;
};
}
