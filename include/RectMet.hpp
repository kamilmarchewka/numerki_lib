#ifndef RECTMET_HPP
#define RECTMET_HPP

#include "Horner.hpp"
#include <vector>

/**
 * @brief Oblicza przybliżoną wartość całki oznaczonej funkcji wielomianowej
 * za pomocą metody prostokątów.
 * @param coeffs Współczynniki wielomianu w postaci wektora.
 * @param a Dolna granica całkowania.
 * @param b Górna granica całkowania.
 * @param n Liczba podziałów (prostokątów) w przedziale [a, b].
 * @return Przybliżona wartość całki oznaczonej.
 */
double rectangle_method(const std::vector<double> &coeffs, double a, double b,
                        int n) {

  double dx = (b - a) / n;
  double sum = 0;
  for (int i = 0; i < n; ++i)
    sum += horner(coeffs, a + i * dx);
  return sum * dx;
}

#endif