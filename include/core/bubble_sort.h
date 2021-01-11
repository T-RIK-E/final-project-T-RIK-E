//
// Created by rtera on 11/24/2020.
//

#pragma once
#include <core/sort.h>

namespace sorting {
class BubbleSort : public Sort {
 public:
  explicit BubbleSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
 private:
  int i_, j_;
};
}
