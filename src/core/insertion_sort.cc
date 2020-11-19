#include <core/insertion_sort.h>

#include <utility>

namespace sorting {
InsertionSort::InsertionSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {

  i = 1;
  key = unsorted_list_[i];
  j = i - 1;
}

void InsertionSort::SortOneStep() {
  /**
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
  **/

  if (i < static_cast<int>(unsorted_list_.size())) {
    first_ = i;
    second_ = j;
    if (j >= 0 && static_cast<int>(unsorted_list_[j]) > key) {
      unsorted_list_[j + 1] = unsorted_list_[j];
      unsorted_list_[j] = key;
      j--;
    } else {
      i++;
      key = unsorted_list_[i];
      j = i - 1;
    }
  }
}
}  // namespace sorting