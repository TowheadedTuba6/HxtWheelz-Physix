#ifndef CUBOID_H
#define CUBOID_H

#include <vector>
#include "../vector3.hpp"

class Cuboid {
private:
  Vector3 position;
  float length;
  float width;
  float height;

public:
  struct MeshData {
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
  };

  Cuboid(Vector3 position, float length, float width, float height);

  float getLength();
  float getWidth();
  float getHeight(); 
  Vector3 getPosition();
  MeshData createCuboidMesh();
};

#endif /* CUBOID_H */