#ifndef SIMPSONMET_HPP
#define SIMPSONMET_HPP

#include "Horner.hpp"
#include <vector>

/**
 * @brief Oblicza przybliżoną wartość całki oznaczonej funkcji wielomianowej
 * za pomocą metody simpsona.
 * @param coeffs Współczynniki wielomianu w postaci wektora.
 * @param a Dolna granica całkowania.
 * @param b Górna granica całkowania.
 * @param n Liczba podziałów (prostokątów) w przedziale [a, b].
 * @return Przybliżona wartość całki oznaczonej.
 */
double simpson_method(const std::vector<double> &coeffs, double a, double b,
                      int n) {
  if (n % 2 != 0)
    ++n; // Simpson's rule requires even n
  double dx = (b - a) / n;
  double sum = horner(coeffs, a) + horner(coeffs, b);

  for (int i = 1; i < n; ++i) {
    double x = a + i * dx;
    sum += horner(coeffs, x) * (i % 2 == 0 ? 2 : 4);
  }

  return sum * dx / 3.0;
}

#endif