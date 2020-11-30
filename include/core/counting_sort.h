//
// Created by rtera on 11/29/2020.
//

#pragma once
#include <core/sort.h>
namespace sorting {
class CountingSort : public Sort {
 public:
  explicit CountingSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
 private:
};
}