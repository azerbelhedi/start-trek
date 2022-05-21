#pragma once
#include "./cartesianCoordinates.h"
#include "./force.h"
#include "./observable.h"

class Object : public Observable {
 public:
  CartesianCoordinates position, velocity, acceleration;
  Force f;
  double m;

  Object(string name, CartesianCoordinates position,
         CartesianCoordinates velocity, CartesianCoordinates acceleration,
         double m, Force f);
  virtual void preCompute(int frameNumber, double time);
  void compute(double framesRate);
  virtual void postCompute();
  virtual Force computeForce(double pressure, double ro);
  void setForce(Force newForce);
};