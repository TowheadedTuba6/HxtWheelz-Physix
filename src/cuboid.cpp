#include <cstring>
#include "../include/PhysicsUtils/Objects/cuboid.hpp"
#include "../include/PhysicsUtils/vector3.hpp"

Cuboid::Cuboid(Vector3 position, float length, float width, float height) : position(position), length(length), width(width), height(height) { }

Vector3 Cuboid::getPosition() { return position; }
float Cuboid::getHeight() { return height; }
float Cuboid::getWidth() { return width; }
float Cuboid::getLength() { return length; }

Cuboid::MeshData Cuboid::createCuboidMesh() {
  Vector3 position = getPosition();
  float length = getLength();
  float width = getWidth();
  float height = getHeight();

  Cuboid::MeshData meshData;

  meshData.vertices = { 
    // Top face
    position.x, position.y, position.z,
    position.x + length, position.y, position.z,
    position.x + length, position.y, position.z - width,
    position.x, position.y, position.z - width,

    // Back face
    position.x, position.y, position.z - width,
    position.x + length, position.y, position.z - width,
    position.x + length, position.y - height, position.z - width,
    position.x, position.y - height, position.z - width,

    // Bottom face
    position.x, position.y - height, position.z - width,
    position.x, position.y - height, position.z,
    position.x + length, position.y - height, position.z,
    position.x + length, position.y - height, position.z - width,

    // Right face
    position.x + length, position.y - height, position.z - width,
    position.x + length, position.y, position.z - width,
    position.x + length, position.y, position.z,
    position.x + length, position.y - height, position.z,

    // Front face
    position.x + length, position.y - height, position.z,
    position.x + length, position.y, position.z,
    position.x, position.y, position.z,
    position.x, position.y - height, position.z,

    // Left face
    position.x, position.y - height, position.z,
    position.x, position.y - height, position.z - width,
    position.x, position.y, position.z - width,
    position.x, position.y, position.z 
  };

  meshData.indices = {
    //  Top face
    0, 1, 2,
    2, 3, 0,
    
    // Back face
    4, 5, 6,
    6, 7, 4,

    // Bottom face
    8, 9, 10,
    10, 11, 8,

    // Right face
    12, 13, 14,
    14, 15, 12,

    // Front face
    16, 17, 18,
    18, 19, 16,

    // Left face
    20, 21, 22,
    22, 23, 20
  };

  return meshData;
}