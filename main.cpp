#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include "EulerMethod.hpp"
#include "MetodaBisekcji.hpp"
#include "MetodaHeuna.hpp"
#include "MetodaNewtona.hpp"
#include "MetodaPktSr.hpp"
#include "MetodaRK4.hpp"
#include "MetodaSiecznych.hpp"
#include "RegulaFalsi.hpp"
#include "SrBladKwadrat.hpp"

using namespace std;

double f1(double x) { return log10(x + 1) - pow(x, 3); }

double f2(double x) { return cosh(x) - sqrt(x * x) - 0.55; }

double f3(double x) { return cos(3 * M_PI * x) / (x + 1); }

int main() {

  find_zeros(f1, -0.99, 3, 0.1, "f1.csv");
  find_zeros(f2, -3, 3, 0.1, "f2.csv");
  find_zeros(f3, -3, 3, 0.1, "f3.csv");

  return 0;
}
