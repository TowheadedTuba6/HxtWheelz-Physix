#include <iostream>
#include "../include/PhysicsUtils/camera.hpp"

Camera::Camera(Vector3 position, float pitch, float yaw) : position(position), pitch(pitch), yaw(yaw) { }

void Camera::move(Directions direction, float deltaTime) {
  switch(direction) {
    case FORWARD:
      position.z += cameraSpeed * deltaTime; 
      break;
    case BACKWORD:
      position.z -= cameraSpeed * deltaTime;
      break;
    case RIGHT:
      position.x += cameraSpeed * deltaTime;
      break;
    case LEFT:
      position.x -= cameraSpeed * deltaTime;
      break;
    case UP:
      position.y += cameraSpeed * deltaTime;
      break;
    case DOWN:
      position.y -= cameraSpeed * deltaTime;
      break;
  }

  //std::cout << "X: " << position.x << ' ' << "Y: " << position.y << ' ' << "Z: " << position.z << std::endl;
}

void Camera::look(float deltaMouseX, float deltaMouseY, float deltaTime) {
  yaw   -= deltaMouseY * sensitivity * deltaTime;
  pitch += deltaMouseX * sensitivity * deltaTime;

  if (yaw > 90.0f) {
    yaw = 90.0f;
  } else if (yaw < -90.0f) {
    yaw = -90.0f;
  }

  if (pitch > 360.0f) {
    pitch = 0.0f;
  } else if (pitch < -360.0f) {
    pitch = 0.0f;
  }

  //std::cout << "Pitch: " << pitch << std::endl << "Yaw: " << yaw << std::endl;
}

Vector3 Camera::calculateCameraTarget(float pitch, float yaw) {
  Vector3 direction;

  pitch = pitch * 3.14159265359f / 180.0f;
  yaw = yaw * 3.14159265359f / 180.0f;

  direction.x = cos(yaw) * cos(pitch);
  direction.y = sin(pitch);
  direction.z = sin(yaw) * cos(pitch);

  direction.normalize();

  return direction;
}

Matrix4 Camera::getViewMatrix() {
  Vector3 cameraTarget = calculateCameraTarget(pitch, yaw);

  Vector3 forward = (cameraTarget - position);
  forward.normalize();
  
  Vector3 right = Vector3(0.0f, 1.0f, 0.0f).cross(forward);
  right.normalize();
  
  Vector3 up = forward.cross(right);
  up.normalize();

  Matrix4 viewMatrix;

  viewMatrix(0, 0) = right.x;
  viewMatrix(1, 0) = right.y;
  viewMatrix(2, 0) = right.z;
  viewMatrix(3, 0) = -right.dot(position);

  viewMatrix(0, 1) = up.x;
  viewMatrix(1, 1) = up.y;
  viewMatrix(2, 1) = up.z;
  viewMatrix(3, 1) = -up.dot(position);

  viewMatrix(0, 2) = -forward.x;
  viewMatrix(1, 2) = -forward.y;
  viewMatrix(2, 2) = -forward.z;
  viewMatrix(3, 2) = forward.dot(position);

  viewMatrix(0, 3) = 0.0f;
  viewMatrix(1, 3) = 0.0f;
  viewMatrix(2, 3) = 0.0f;
  viewMatrix(3, 3) = 1.0f;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << viewMatrix(i, j) << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  return viewMatrix;
}

Matrix4 Camera::getProjectionMatrix(float fov, float aspectRatio, float nearPlane, float farPlane) {
  float fovRadians = fov * (3.14159265f / 180.0f);
  float tanHalfFOV = std::tan(fovRadians / 2.0f);

  Matrix4 projectionMatrix;
  
  projectionMatrix(0, 0) = 1.0f / (aspectRatio * tanHalfFOV);
  projectionMatrix(1, 1) = 1.0f / tanHalfFOV;
  projectionMatrix(2, 2) = -(farPlane + nearPlane) / (farPlane - nearPlane);
  projectionMatrix(2, 3) = -(2.0f * farPlane * nearPlane) / (farPlane - nearPlane);
  projectionMatrix(3, 2) = -1.0f;

  return projectionMatrix;
}