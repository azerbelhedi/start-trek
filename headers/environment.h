#pragma once
#include <iostream>
#include <vector>

#include "./force.h"
#include "./object.h"

using namespace std;

class Environment {
 public:
  double pressure, ro;
  vector<Object *> objects;

  Environment();
  void run(double framesRate, double duration);
  void addObject(Object *object);
  Force computeForce();
};