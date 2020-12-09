#include <cinder/gl/gl.h>
#include <visualizer/sorting_visualizer_app.h>
#include <algorithm>
#include <random>

using glm::vec2;
namespace sorting {

namespace visualizer {

SortingApp::SortingApp() : top_left_(glm::vec2(0, 0)) {
  ci::app::setWindowSize((int)kWindowX, (int)kWindowY);

  InitializeList();
  it = sort_list_.begin();
}

void SortingApp::draw() {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidRect(
      ci::Rectf(top_left_, top_left_ + glm::vec2(kWindowX, kWindowY)));
  DrawList();
  PrintName();
}

void SortingApp::update() {
  (*it)->SortOneStep();
}

void SortingApp::cleanup() {
  for (it = sort_list_.begin(); it != sort_list_.end(); it++) {
    delete it._Ptr->_Myval;
  }
}

void SortingApp::DrawList() const {
  size_t width = 0;
  for (size_t height : (*it)->GetUnsortedList()) {
    glm::vec2 top_left =
        top_left_ + glm::vec2(width, 0) + glm::vec2(0, kWindowY - height);

    if ((*it)->GetHeight1() == height ||
        (*it)->GetHeight2() == height) {
      ci::gl::color(ci::Color("red"));
    } else {
      ci::gl::color(ci::Color("black"));
    }
    ci::gl::drawSolidRect(
        ci::Rectf(top_left, top_left + glm::vec2(kWidth, height)));

    width += 10;
  }
}

void SortingApp::PrintName() const {
  ci::gl::drawString((*it)->GetName(), glm::vec2(15, 20),
                     ci::Color(0, 0, 0), ci::Font("Title Font", 30));
}

void SortingApp::InitializeList() {
  std::vector<size_t> list;
  list.reserve(100);
  for (size_t i = 0; i < 100; i++) {
    list.push_back(i);
  }
  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(list), std::end(list), rng);

  sort_list_.push_back(new BubbleSort(list));
  sort_list_.push_back(new CombSort(list));
  sort_list_.push_back(new CountingSort(list));
  sort_list_.push_back(new HeapSort(list));
  sort_list_.push_back(new InsertionSort(list));
  sort_list_.push_back(new MergeSort(list));
  sort_list_.push_back(new QuickSort(list));
  sort_list_.push_back(new SelectionSort(list));
  sort_list_.push_back(new ShellSort(list));
}

void SortingApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_LEFT:
      if (it != sort_list_.begin()) {
        it--;
      }
      break;
    case ci::app::KeyEvent::KEY_RIGHT:
      if (it != --sort_list_.end()) {
        it++;
      }
      break;
  }
}
}  // namespace visualizer
}  // namespace sorting
