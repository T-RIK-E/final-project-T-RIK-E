#include <cinder/gl/gl.h>
#include <visualizer/sorting_visualizer_app.h>

using glm::vec2;
namespace sorting {

namespace visualizer {

SortingApp::SortingApp()
    : container(glm::vec2(50, 50), 50, 50) {
  ci::app::setWindowSize((int)kWindowX, (int)kWindowY);
}

void SortingApp::draw() {
  container.DrawFrame();
}

void SortingApp::update() {
}

}  // namespace visualizer
}  // namespace sorting
