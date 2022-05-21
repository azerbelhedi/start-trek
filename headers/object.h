#pragma once
#include "./cartesianCoordinates.h"
#include "./force.h"

class Object {
 public:
  CartesianCoordinates position, velocity, acceleration;
  Force f;
  double m;

  Object(CartesianCoordinates position, CartesianCoordinates velocity,
         CartesianCoordinates acceleration, double m, Force f);
  virtual void preCompute(int frameNumber, double time);
  void compute(double framesRate);
  virtual void postCompute();
  virtual Force computeForce(double pressure, double ro);
  void setForce(Force newForce);
};