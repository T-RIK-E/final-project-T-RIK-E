#include <cinder/gl/gl.h>
#include <visualizer/sorting_visualizer_app.h>

using glm::vec2;
namespace sorting {

namespace visualizer {

SortingApp::SortingApp() {
  ci::app::setWindowSize((int)kWindowX, (int)kWindowY);
}

void SortingApp::draw() {
}

void SortingApp::update() {
}

}  // namespace visualizer
}  // namespace sorting
