#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include <visualizer/algorithms.h>

namespace sorting {

namespace visualizer {

/**
 * Allows user to view how different sorting algorithms sort under the hood.
 */
class SortingApp : public ci::app::App {
 public:
  /**
   * Base constructor
   */
  SortingApp();

  /**
   * Draws the app
   */
  void draw() override;

  /**
   * Updates the internal state of the app.
   */
  void update() override;

  /**
   * Destroys and cleans up all the memory allocated on the heap.
   */
  void cleanup() override;

  /**
   * Executes commands on keys pressed down.
   * @param event The event of the key being pressed
   */
  void keyDown(ci::app::KeyEvent event) override;

 private:
  // This is the window size of the app.
  const size_t kWindowX = 1000;
  const size_t kWindowY = 875;

  // This is the width between each of the bars in the visualizer
  const float kWidth = 10.0f;

  // For visualization purposes.
  const std::string kAccess = "Array Access: ";

  // List of the different types of sorting algorithms
  std::list<Sort*> sort_list_;
  std::list<Sort*>::iterator it_;

  // Top left of the app window
  glm::vec2 top_left_;

  // Whether the app should continue updating the internal state or not
  bool stopped_;

  /**
   * Draws each of the rectangles in the list as it gets sorted
   */
  void DrawList() const;

  /**
   * Prints the name of the current sort
   */
  void PrintName() const;

  /**
   * Initializes sort_list_
   */
  void InitializeList();
};

}  // namespace visualizer

}  // namespace sorting
