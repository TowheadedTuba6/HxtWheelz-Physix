#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include <future>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "vector3.hpp"

class Camera {
private:
  Vector3 position;
  float pitch;
  float yaw;
  float cameraSpeed = 2.0f;

public:
  enum Directions {
    FORWARD,
    BACKWORD,
    LEFT,
    RIGHT,
    UP,
    DOWN
  };

  Camera(Vector3 position, float pitch, float yaw);

  void move(Directions direction, float deltaTime);
  void look(float deltaMouseX, float deltaMouseY);
};

#endif /* CAMERA_H */