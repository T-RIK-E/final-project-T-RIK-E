//
// Created by rtera on 11/30/2020.
//

#pragma once
#include <core/sort.h>

namespace sorting {
class CombSort : public Sort {
 public:
  CombSort() = default;
  explicit CombSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
 private:
  size_t gap_;
  size_t i_;
  bool swapped_;
  bool go_;
  void GetNextGap();
};
}