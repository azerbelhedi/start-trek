#include "../headers/environment.h"

#include "../headers/object.h"

Environment::Environment() {}

void Environment::addObject(Object *object) { objects.push_back(object); }

void Environment::run(double framesRate, double duration) {
  for (int i = 0; i < duration * framesRate; i++) {
    for (vector<Object *>::iterator ob = begin(objects); ob != end(objects);
         ob++) {
      (*ob)->preCompute(i, i / framesRate);
      vector<double> variables;
      CartesianCoordinates p = (*ob)->position;
      CartesianCoordinates v = (*ob)->velocity;
      CartesianCoordinates a = (*ob)->acceleration;
      CartesianCoordinates f = (*ob)->f.weightedDirection;

      variables = {i / framesRate,
                   p.x,
                   p.y,
                   p.z,
                   v.x,
                   v.y,
                   v.z,
                   a.x,
                   a.y,
                   a.z,
                   f.x,
                   f.y,
                   f.z};

      (*ob)->updateVariables(variables);
      (*ob)->compute(framesRate);
      (*ob)->computeForce(pressure, ro);
      (*ob)->postCompute();
    }
  }
}