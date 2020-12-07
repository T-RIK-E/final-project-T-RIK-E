#include <core/sort.h>

#include <utility>
#include <random>
#include <algorithm>

namespace sorting {
Sort::Sort(std::vector<size_t> unsorted_list)
    : unsorted_list_(std::move(unsorted_list)) {}

Sort::~Sort() = default;

const std::vector<size_t>& Sort::GetUnsortedList() const {
  return unsorted_list_;
}

const size_t Sort::GetHeight1() const {
  return height1_;
}

const size_t Sort::GetHeight2() const {
  return height2_;
}

const std::string Sort::GetName() const {
  return name_;
}

void Sort::swap(size_t& a, size_t& b) {
  size_t temp = a;
  a = b;
  b = temp;
}

std::vector<size_t> Sort::GenerateList() {
  std::vector<size_t> list;
  list.reserve(100);
  for (size_t i = 0; i < 100; i++) {
    list.push_back(i);
  }
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(list), std::end(list), rng);

  return list;
}
}  // namespace sorting