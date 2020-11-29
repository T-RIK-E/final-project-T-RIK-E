//
// Created by rtera on 11/26/2020.
//

#pragma once
#include <core/sort.h>

#include <queue>

using std::vector;
namespace sorting {
class MergeSort : public Sort {
 public:
  explicit MergeSort(std::vector<size_t> unsorted_list);
  void SortOneStep() override;

 private:
  std::queue<vector<size_t>> smaller_arrays;
  vector<size_t> MergeArrays(const vector<size_t>& arr1,
                            const vector<size_t>& arr2);
  void SplitArray();
};
}  // namespace sorting
