#include <fstream>
#include <iomanip>
#include <iostream>

#include "../../headers/environment.h"
#include "../../headers/object.h"

using namespace std;

class LowEarthAtmosphere : public Environment {};

class Ball : public Object {
 public:
  double dragCof;
  double area;

  Ball(CartesianCoordinates position, CartesianCoordinates velocity,
       CartesianCoordinates acceleration, double m, Force f, double dragCof,
       double area)
      : Object(position, velocity, acceleration, m, f),
        dragCof(dragCof),
        area(area) {
    ofstream plotFile;
    plotFile.open("position.dat");
    plotFile << "# position.dat\n"
             << "# X" << setw(12) << "Y\n";
  }

  void preCompute() {
    cout << "position: x: " << position.x << " y: " << position.y
         << " z: " << position.z << "\n";

    cout << "velocity: x: " << velocity.x << " y: " << velocity.y
         << " z: " << velocity.z << "\n";

    cout << "force: x: " << f.weightedDirection.x
         << " y: " << f.weightedDirection.y << " z: " << f.weightedDirection.z
         << "\n";

    ofstream plotFile;
    plotFile.open("position.dat", ios_base::app);
    fixed;
    setprecision(1);
    plotFile << " " << left << setw(12) << position.x << setw(12) << position.y
             << "\n";
  }

  Force computeForce(double p, double ro) {
    f.weightedDirection.x -= (ro * velocity.x * dragCof * area) / 2;
    f.weightedDirection.y -= (ro * velocity.y * dragCof * area) / 2;
    +m * 9.81;
    f.weightedDirection.z -= (ro * velocity.z * dragCof * area) / 2;

    return f;
  }
};

int main() {
  LowEarthAtmosphere earth;
  earth.pressure = 10000;
  earth.ro = 1.225;

  CartesianCoordinates position(0, 0, 0);
  CartesianCoordinates velocity(0, 0, 0);
  CartesianCoordinates acceleration(0, 0, 0);

  CartesianCoordinates forceWeightedDirection(15, 5, 0);
  Force initialForce(forceWeightedDirection, 15.81);
  double m = 0.5;
  double dragCof = 0.5;
  double area = 0.05;

  Ball* ball = new Ball(position, velocity, acceleration, m, initialForce,
                        dragCof, area);

  earth.addObject(ball);

  earth.run(1, 200);

  return 0;
}