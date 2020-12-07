//
// Created by rtera on 11/17/2020.
//

#pragma once
#include <cinder/gl/gl.h>
#include <core/sort.h>
#include <list>


namespace sorting {
class Container {
 public:
  Container(const glm::vec2& top_left,
            size_t pixels_x,
            size_t pixels_y);

  void DrawFrame() const;
  void Update();
  void CleanUp();
  void Decrement();
  void Increment();
 private:
  const float kWidth = 10.0f;
  std::list<Sort*> sort_list_;
  std::list<Sort*>::iterator it;
  glm::vec2 top_left_;
  size_t pixels_x_;
  size_t pixels_y_;

  void DrawList() const;
  void PrintName() const;
  void InitializeList();
};
}  // namespace sorting
