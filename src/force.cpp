#include "../headers/force.h"

#include <iostream>

#include "../headers/cartesianCoordinates.h"

using namespace std;

Force::Force(CartesianCoordinates weightedDirection, double magnitude)
    : weightedDirection(weightedDirection), magnitude(magnitude) {}