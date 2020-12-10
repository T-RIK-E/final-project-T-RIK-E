//
// Created by rtera on 11/30/2020.
//

#pragma once
#include <core/sort.h>

namespace sorting {
class CombSort : public Sort {
 public:
  CombSort();
  explicit CombSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;
  void ReInitialize() override;
 private:
  // Gap to increment by
  size_t gap_;
  // Index i
  size_t i_;
  bool swapped_;
  bool go_;

  /**
   * Get the next smaller gap to increment by.
   */
  void GetNextGap();
};
} // namespace sorting