#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Observable {
  vector<vector<double>> variables;
  vector<string> variablesNames;
  string name;

 public:
  Observable(string name, vector<string> variablesNames);
  void updateVariables(vector<double> newVariables);
  void saveVariablesToFile();
};