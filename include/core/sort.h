//
// Created by rtera on 11/17/2020.
//

#pragma once
#include <vector>
#include <algorithm>
#include <random>

namespace sorting {
class Sort {
 public:
  Sort();
  explicit Sort(std::vector<size_t> unsorted_list);
  virtual ~Sort();
  virtual void SortOneStep() = 0;
  virtual void ReInitialize() = 0;

  const std::vector<size_t>& GetUnsortedList() const;
  const size_t GetHeight1() const;
  const size_t GetHeight2() const;
  const std::string GetName() const;
  const size_t GetAccess() const;
 protected:
  void swap(size_t& a, size_t& b);
  void GenerateList();

  std::vector<size_t> unsorted_list_;
  size_t height1_;
  size_t height2_;
  size_t access_;
  std::string name_;
};
} // namespace sorting
