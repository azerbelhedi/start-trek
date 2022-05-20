#pragma once
#include "./cartesianCoordinates.h"

class Force {
 public:
  CartesianCoordinates weightedDirection;
  double magnitude;

  Force(CartesianCoordinates weightedDirection, double magnitude);
};