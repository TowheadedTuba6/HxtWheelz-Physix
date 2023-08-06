#include <iostream>
#include <future>
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

  std::cout << "X: " << position.x << ' ' << "Y: " << position.y << ' ' << "Z: " << position.z << std::endl;
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

  std::cout << "Pitch: " << pitch << std::endl << "Yaw: " << yaw << std::endl;
}