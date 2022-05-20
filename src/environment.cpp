#include "../headers/environment.h"

#include "../headers/object.h"

Environment::Environment() {}

void Environment::addObject(Object *object) { objects.push_back(object); }

void Environment::run(double framesRate, double duration) {
  for (int i = 0; i < duration / framesRate; i++) {
    for (vector<Object *>::iterator ob = begin(objects); ob != end(objects);
         ob++) {
      (*ob)->preCompute();
      (*ob)->compute(framesRate);
      (*ob)->computeForce(pressure, ro);
      (*ob)->postCompute();
    }
  }
}