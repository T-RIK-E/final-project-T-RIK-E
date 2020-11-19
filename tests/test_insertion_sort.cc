#include <catch2/catch.hpp>
#include <core/insertion_sort.h>
#include <vector>

using sorting::InsertionSort;
TEST_CASE("Test SortOneStep") {
  std::vector<size_t> list;
  list.push_back(4);
  list.push_back(3);
  list.push_back(2);
  InsertionSort sort(list);
  SECTION("One Step") {
    sort.SortOneStep();
    REQUIRE(sort.GetUnsortedList()[0] == 3);
    REQUIRE(sort.GetUnsortedList()[1] == 4);
    REQUIRE(sort.GetUnsortedList()[2] == 2);
  }

  SECTION("Two Steps") {
    sort.SortOneStep();
    sort.SortOneStep();
    REQUIRE(sort.GetUnsortedList()[0] == 3);
    REQUIRE(sort.GetUnsortedList()[1] == 4);
    REQUIRE(sort.GetUnsortedList()[2] == 2);
  }

  SECTION("Three Steps") {
    sort.SortOneStep();
    sort.SortOneStep();
    sort.SortOneStep();
    REQUIRE(sort.GetUnsortedList()[0] == 3);
    REQUIRE(sort.GetUnsortedList()[1] == 2);
    REQUIRE(sort.GetUnsortedList()[2] == 4);
  }
}