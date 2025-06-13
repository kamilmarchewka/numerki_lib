#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>

#include "RegulaFalsi.hpp"

double f1(double x) { return sin(1 / x); }

int main() {

  find_zeros(f1, 0.0, 0.5, 0.001, "f1.csv");

  return 0;
}