#include <core/insertion_sort.h>

#include <utility>

namespace sorting {
InsertionSort::InsertionSort(std::vector<size_t> unsorted_list)
    : Sort(std::move(unsorted_list)) {
}

void InsertionSort::SortOneStep() {

}
}  // namespace sorting