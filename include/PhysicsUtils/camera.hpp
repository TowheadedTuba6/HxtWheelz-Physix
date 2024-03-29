#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>
#include <future>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "vector3.hpp"
#include "matrix4.hpp"

// Fix to work with private (chatgpt)
class Camera {
private:
  Vector3 position;
  float pitch;
  float yaw;
  float cameraSpeed = 2.0f;
  float sensitivity = 10.0f;

  Vector3 calculateCameraTarget(float pitch, float yaw);

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
  void look(float deltaMouseX, float deltaMouseY, float deltaTime);
  Matrix4 getViewMatrix();
  Matrix4 getProjectionMatrix(float fov, float aspectRatio, float nearPlan, float farPlane);
};

#endif /* CAMERA_H */