#include <visualizer/sorting_visualizer_app.h>

using sorting::visualizer::SortingApp;

void prepareSettings(SortingApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(SortingApp, ci::app::RendererGl, prepareSettings);
