#include "../headers/observable.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

Observable::Observable(string name, vector<string> variablesNames)
    : name(name), variablesNames(variablesNames) {
  for (auto i = variablesNames.begin(); i != variablesNames.end(); i++) {
    variables.push_back({});
  }
}

void Observable::updateVariables(vector<double> newVariables) {
  for (int i = 0; i < newVariables.size(); i++) {
    variables[i].push_back(newVariables[i]);
  }
}

void Observable::saveVariablesToFile() {
  ofstream file;
  file.open(name);

  file << "# " << name << "\n# ";
  for (vector<string>::iterator name = variablesNames.begin();
       name != variablesNames.end(); name++) {
    file << *name << setw(12);
  }

  file << "\n";

  for (int frame = 0; frame < variables[0].size(); frame++) {
    file << " " << left;
    for (int v = 0; v < variables.size(); v++) {
      file << setw(12) << variables[v][frame];
    }
    file << "\n";
  }
}