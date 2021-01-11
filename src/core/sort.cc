#include <core/sort.h>

#include <algorithm>
#include <random>
#include <utility>

namespace sorting {
// Sets access to 0 and Generates a default unsorted list
Sort::Sort() : access_(0) {
  GenerateList();
}

// Set access to 0 and use the given unsorted list
Sort::Sort(std::vector<size_t> unsorted_list)
    : unsorted_list_(std::move(unsorted_list)), access_(0) {
}

// Set destructor to default
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

const size_t Sort::GetAccess() const {
  return access_;
}

void Sort::swap(size_t& a, size_t& b) {
  // Set temp to a
  size_t temp = a;
  // Set a = b
  a = b;
  // Set b to temp
  b = temp;
  // Increase array access by 2, because to switch two elements we need to
  // access the array twice.
  access_ += 2;
}

void Sort::GenerateList() {
  // Fill the array with numbers 0 - 100
  unsorted_list_.reserve(100);
  for (size_t i = 0; i < 100; i++) {
    unsorted_list_.push_back(i);
  }

  // Shuffle the list
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(unsorted_list_), std::end(unsorted_list_), rng);
}
}  // namespace sorting