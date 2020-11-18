//
// Created by rtera on 11/15/2020.
//
#pragma once
#include <vector>

namespace sorting {
class InsertionSort {
 public:
  void SortOnce() {}

 private:
  std::vector<size_t> unsorted_list;
  size_t i, key, j;

};
}
