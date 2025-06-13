
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

#include "GaussLegendre.hpp"

// Funkcje podcałkowe
double integrand1(double x) { return x * x * pow(sin(x), 3); }

double integrand2(double x) { return exp(x * x) * (1 - x); }

double integrand3(double x) { return (x * pow(cos(x), 3)); }

void evaluate_integral(std::function<double(double)> f, double a, double b,
                       double exact, int subdivs) {
  std::cout << "Przedziały: " << subdivs << std::endl;
  std::cout << "Dokładna wartość: " << exact << std::endl;

  for (int n : {2, 3, 4}) {
    double approx = gauss_legendre_subdivided(f, a, b, n, subdivs);
    double abs_err = std::abs(approx - exact);
    std::cout << n << "-węzłowa: " << std::setprecision(15) << approx
              << "    Błąd bezwzględny: " << std::scientific << abs_err << "\n";
  }

  std::cout << "-----------------------------\n";
}
int main() {
  int subdivs = 1000;

  std::cout << std::fixed << std::setprecision(10);

  double exact1 = -10.1010101105917;
  double exact2 = -9876.54321007546;
  double exact3 = 4.202504090000006;

  evaluate_integral(integrand1, 1.0, 4.764798248, exact1, subdivs);
  evaluate_integral(integrand2, -2.0, 3.20870913294, exact2, subdivs);
  evaluate_integral(integrand3, -3.5, 6.52968912439344, exact3, subdivs);

  return 0;
}
