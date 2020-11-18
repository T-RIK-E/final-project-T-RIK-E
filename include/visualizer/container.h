//
// Created by rtera on 11/17/2020.
//

#pragma once
#include <cinder/gl/gl.h>


namespace sorting {
class Container {
 public:
  Container(const glm::vec2& top_left,
            size_t pixels_x,
            size_t pixels_y);

  void DrawContainer() const;
 private:
  glm::vec2 top_left_;
  size_t pixels_x_;
  size_t pixels_y_;
};
}
