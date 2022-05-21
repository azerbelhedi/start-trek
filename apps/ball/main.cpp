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

  Ball(string name, CartesianCoordinates position,
       CartesianCoordinates velocity, CartesianCoordinates acceleration,
       double m, Force f, double dragCof, double area)
      : Object(name, position, velocity, acceleration, m, f),
        dragCof(dragCof),
        area(area) {
    ofstream positionFile, velocityFile, accelerationFile, forceFile;

    positionFile.open("position.dat");
    velocityFile.open("velocity.dat");
    accelerationFile.open("acceleration.dat");
    forceFile.open("force.dat");

    positionFile << "# position.dat\n"
                 << "# T" << setw(12) << "X" << setw(12) << "Y\n";

    velocityFile << "# velocity.dat\n"
                 << "# T" << setw(12) << "X" << setw(12) << "Y\n";

    accelerationFile << "# acceleration.dat\n"
                     << "# T" << setw(12) << "X" << setw(12) << "Y\n";

    forceFile << "# force.dat\n"
              << "#T" << setw(12) << "X" << setw(12) << "Y\n";
  }

  void preCompute(int frameNumber, double time) {
    ofstream positionFile, velocityFile, accelerationFile, forceFile;

    positionFile.open("position.dat", ios_base::app);
    velocityFile.open("velocity.dat", ios_base::app);
    accelerationFile.open("acceleration.dat", ios_base::app);
    forceFile.open("force.dat", ios_base::app);

    positionFile << " " << left << setw(12) << time << setw(12) << position.x
                 << setw(12) << position.y << "\n";

    velocityFile << " " << left << setw(12) << time << setw(12) << velocity.x
                 << setw(12) << velocity.y << "\n";

    accelerationFile << " " << left << setw(12) << time << setw(12)
                     << acceleration.x << setw(12) << acceleration.y << "\n";

    forceFile << " " << left << setw(12) << time << setw(12)
              << f.weightedDirection.x << setw(12) << f.weightedDirection.y
              << "\n";
  }

  Force computeForce(double p, double ro) {
    f.weightedDirection.x -= (ro * velocity.x * dragCof * area) / 2;
    f.weightedDirection.y -=
        ((ro * velocity.y * dragCof * area) / 2 + m * 9.81);
    f.weightedDirection.z -= (ro * velocity.z * dragCof * area) / 2;

    if (position.y <= 0) {
      f.weightedDirection.x = 0;
      f.weightedDirection.y = 0;
      f.weightedDirection.z = 0;

      acceleration.x = 0;
      acceleration.y = 0;
      acceleration.z = 0;

      velocity.x = 0;
      velocity.y = 0;
      velocity.z = 0;
    }

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

  CartesianCoordinates forceWeightedDirection(50, 150, 0);
  Force initialForce(forceWeightedDirection, 0);
  double m = 0.2;
  double dragCof = 0.5;
  double area = 0.05;

  Ball* ball = new Ball("steal-ball", position, velocity, acceleration, m,
                        initialForce, dragCof, area);

  earth.addObject(ball);

  earth.run(50, 15);

  ball->saveVariablesToFile();

  return 0;
}