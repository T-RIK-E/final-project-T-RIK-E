//
// Created by rtera on 11/17/2020.
//

#pragma once
#include <vector>
#include <algorithm>
#include <random>

namespace sorting {

/**
 * This abstract class is a framework for all of the sorting algorithms
 */
class Sort {
 public:
  // Base sorting constructor
  Sort();
  // Takes a given unsorted list and initializes using that list
  explicit Sort(std::vector<size_t> unsorted_list);
  // Base destructor
  virtual ~Sort();

  /**
   * Updates one step of the sorting process.
   */
  virtual void SortOneStep() = 0;
  /**
   * Initializes the sort to the original, unsorted state
   */
  virtual void ReInitialize() = 0;

  const std::vector<size_t>& GetUnsortedList() const;
  const size_t GetHeight1() const;
  const size_t GetHeight2() const;
  const std::string GetName() const;
  const size_t GetAccess() const;
 protected:
  /**
   * Swaps location of numbers a and b
   */
  void swap(size_t& a, size_t& b);
  /**
   * Generates a randomized list from 0 to 100
   */
  void GenerateList();

  // Unsorted list to sort
  std::vector<size_t> unsorted_list_;
  // Heights that should be highlighted
  size_t height1_;
  size_t height2_;
  // Count of array accesses
  size_t access_;
  // Name of the sort
  std::string name_;
};
} // namespace sorting
