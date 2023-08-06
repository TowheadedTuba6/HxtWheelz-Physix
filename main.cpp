#include <iostream>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/PhysicsUtils/camera.hpp"
#include "../include/PhysicsUtils/vector3.hpp"

// Updates the cameras information, (x, y, z) positions and the pitch(left, right) and yaw(up, down)
void updateCamera(GLFWwindow* window, Camera& camera, float mouseDeltaX, float mouseDeltaY, float deltaTime) {
  // Check if the user is moving the camera (x, y, z) positions
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    camera.move(camera.FORWARD, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    camera.move(camera.BACKWORD, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    camera.move(camera.LEFT, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    camera.move(camera.RIGHT, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
    camera.move(camera.UP, deltaTime);
  } else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
    camera.move(camera.DOWN, deltaTime);
  }

  // Check if the user is looking around, (pitch, yaw)
  if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
    camera.look(mouseDeltaX, mouseDeltaY, deltaTime);
  }
}

int main() {
  // Initialize GLFW
  glfwInit();

  if (!glfwInit()) {
    std::cout << "FAILED TO INIT GLFW!" << std::endl;
    return -1;
  }
    
  // Set GLFW to use the OpenGL core profile
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
  // Create a GLFW window
  GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    std::cout << "WINDOW DID NOT OPEN!" << std::endl;
    return -1;
  }
    
  glfwMakeContextCurrent(window);

  // Initialize GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "FAILED TO INIT GLAD!" << std::endl;
    return -1;
  }
    
  // Variables
  double deltaTime     = 0.0;
  double lastFrameTime = glfwGetTime();

  // Tracking mouse
  double lastMouseX, lastMouseY;
  glfwGetCursorPos(window, &lastMouseX, &lastMouseY);

  // Camera related
  float yaw   = 0.0f;
  float pitch = 0.0f;
  Vector3 cameraPosition(0.0f, 0.0f, 0.0f);
  Camera camera(cameraPosition, pitch, yaw);

  // Rendering loop
  while (!glfwWindowShouldClose(window)) {
    double currentFrameTime = glfwGetTime();
    deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;

    double currentMouseX, currentMouseY, mouseDeltaX, mouseDeltaY;
    glfwGetCursorPos(window, &currentMouseX, &currentMouseY);

    mouseDeltaX = currentMouseX - lastMouseX;
    mouseDeltaY = currentMouseY - lastMouseY;

    updateCamera(window, camera, mouseDeltaX, mouseDeltaY, deltaTime);

    lastMouseX = currentMouseX;
    lastMouseY = currentMouseY;

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
    
  // Cleanup
  glfwTerminate();
    
  return 0;
}
