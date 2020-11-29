#include <core/merge_sort.h>

namespace sorting {
MergeSort::MergeSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
  SplitArray();
}

void MergeSort::SortOneStep() {
  while (smaller_arrays.size() > 1) {
    vector<size_t> arr1 = smaller_arrays.front();
    smaller_arrays.pop();
    vector<size_t> arr2 = smaller_arrays.front();
    smaller_arrays.pop();
    smaller_arrays.push(MergeArrays(arr1, arr2));
  }
  unsorted_list_ = smaller_arrays.front();
}

vector<size_t> MergeSort::MergeArrays(const vector<size_t> &arr1,
                                     const vector<size_t> &arr2) {
  vector<size_t> merged(arr1.size()+arr2.size());

  size_t first_index = 0;
  size_t second_index = 0;
  for (unsigned int & i : merged) {
    if (first_index == arr1.size()) {
      i = arr2[second_index++];
    } else if (second_index == arr2.size()) {
      i = arr1[first_index++];
    } else if (arr1[first_index] < arr2[second_index]) {
      i = arr1[first_index++];
    } else {
      i = arr2[second_index++];
    }
  }

  return merged;
}

void MergeSort::SplitArray() {
  for (unsigned int i : unsorted_list_) {
    smaller_arrays.push(vector<size_t>{i});
  }
}
}  // namespace sorting