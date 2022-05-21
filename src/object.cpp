#include "../headers/object.h"

#include <iostream>

#include "../headers/cartesianCoordinates.h"
#include "../headers/force.h"

using namespace std;

Object::Object(string name, CartesianCoordinates position,
               CartesianCoordinates velocity, CartesianCoordinates acceleration,
               double m, Force f)
    : Observable(name, {"t", "x", "y", "z", "v_x", "v_y", "v_z", "a_x", "a_y",
                        "a_z", "f_x", "f_y", "f_z"}),
      position(position),
      velocity(velocity),
      acceleration(acceleration),
      m(m),
      f(f) {}

void Object::preCompute(int frameNumber, double time) {}

void Object::compute(double framesRate) {
  acceleration.x = f.weightedDirection.x / m;
  acceleration.y = f.weightedDirection.y / m;
  acceleration.z = f.weightedDirection.z / m;

  velocity.x += acceleration.x / framesRate;
  velocity.y += acceleration.y / framesRate;
  velocity.z += acceleration.z / framesRate;

  position.x += velocity.x / framesRate;
  position.y += velocity.y / framesRate;
  position.z += velocity.z / framesRate;
}

void Object::postCompute() {}

Force Object::computeForce(double pressure, double ro) {
  CartesianCoordinates forceWeightedDirection(0, 0, 0);
  Force f(forceWeightedDirection, 0);
  return f;
}

void Object::setForce(Force newForce) { f = newForce; }