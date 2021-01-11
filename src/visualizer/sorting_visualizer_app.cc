#include <cinder/gl/gl.h>
#include <visualizer/sorting_visualizer_app.h>
#include <algorithm>
#include <random>

using glm::vec2;
namespace sorting {

namespace visualizer {

SortingApp::SortingApp() : top_left_(vec2(0, 0)) {
  // Set window size
  ci::app::setWindowSize((int)kWindowX, (int)kWindowY);

  // Initialize internal member variables.
  InitializeList();
  it_ = sort_list_.begin();
  stopped_ = false;
}

void SortingApp::draw() {
  // Draw white background
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(
      ci::Rectf(top_left_, top_left_ + vec2(kWindowX, kWindowY)));

  // Draw the rectangles and print the name of the sort
  DrawList();
  PrintName();
}

void SortingApp::update() {
  // If the app is not stopped, update the current sort by a step
  if (!stopped_) {
    (*it_)->SortOneStep();
  }
}

void SortingApp::cleanup() {
  // Destroy every sort in sort_list_ to clear from heap
  for (it_ = sort_list_.begin(); it_ != sort_list_.end(); it_++) {
    delete it_._Ptr->_Myval;
  }
}

void SortingApp::DrawList() const {
  // Set the x value of the bars to 0
  size_t width = 0;
  // Loop through the unsorted list of the array
  for (size_t height : (*it_)->GetUnsortedList()) {
    glm::vec2 top_left =
        top_left_ + vec2(width, 0) + vec2(0, kWindowY - height);

    // If the bar needs to be highlighted red, highlight red
    if ((*it_)->GetHeight1() == height ||
        (*it_)->GetHeight2() == height) {
      ci::gl::color(ci::Color("red"));
    } else {
      // Else color black
      ci::gl::color(ci::Color("black"));
    }
    // Draw the rectangle
    ci::gl::drawSolidRect(
        ci::Rectf(top_left, top_left + vec2(kWidth, height)));

    // Add to the x value of the rectangle.
    width += 10;
  }
}

void SortingApp::PrintName() const {
  // Print the name of the string
  ci::gl::drawString((*it_)->GetName(), vec2(15, 20),
                     ci::Color(0, 0, 0), ci::Font("Title Font", 30));

  // Print the amount of array access.
  ci::gl::drawString(kAccess + std::to_string((*it_)->GetAccess()), vec2(15, 70),
                     ci::Color(0, 0, 0), ci::Font("Title Font", 30));
}

void SortingApp::InitializeList() {
  // Push a different type of sort and put onto heap.
  sort_list_.push_back(new BubbleSort());
  sort_list_.push_back(new CombSort());
  sort_list_.push_back(new CountingSort());
  sort_list_.push_back(new HeapSort());
  sort_list_.push_back(new InsertionSort());
  sort_list_.push_back(new MergeSort());
  sort_list_.push_back(new QuickSort());
  sort_list_.push_back(new SelectionSort());
  sort_list_.push_back(new ShellSort());
}

void SortingApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    // If left is pressed and it is not the beginning sort,
    // -- on the iterator
    case ci::app::KeyEvent::KEY_LEFT:
      if (it_ != sort_list_.begin()) {
        it_--;
      }
      break;
    // If right is pressed and it is not the end sort,
    // ++ on the iterator
    case ci::app::KeyEvent::KEY_RIGHT:
      if (it_ != --sort_list_.end()) {
        it_++;
      }
      break;
    // If space is pressed, stop the updating
    case ci::app::KeyEvent::KEY_SPACE:
      stopped_ = !stopped_;
      break;
    // If r is pressed, reset the sort to beginning.
    case ci::app::KeyEvent::KEY_r:
      it_._Ptr->_Myval->ReInitialize();
      break;
  }
}
}  // namespace visualizer
}  // namespace sorting
