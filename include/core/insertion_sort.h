//
// Created by rtera on 11/15/2020.
//
#pragma once
#include <vector>
#include <core/sort.h>

namespace sorting {
class InsertionSort : public Sort{
 public:
  InsertionSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
 private:
  int i, key, j;

};
}
