#ifndef TRAPMET_HPP
#define TRAPMET_HPP

#include "Horner.hpp"
#include <vector>

/**
 * @brief Oblicza przybliżoną wartość całki oznaczonej funkcji wielomianowej
 * za pomocą metody trapezów.
 * @param coeffs Współczynniki wielomianu w postaci wektora.
 * @param a Dolna granica całkowania.
 * @param b Górna granica całkowania.
 * @param n Liczba podziałów (trapezów) w przedziale [a, b].
 * @return Przybliżona wartość całki oznaczonej.
 */
double trapezoidal_method(const std::vector<double> &coeffs, double a, double b,
                          int n) {
  double dx = (b - a) / n;
  double sum = 0.5 * (horner(coeffs, a) + horner(coeffs, b));
  for (int i = 1; i < n; ++i)
    sum += horner(coeffs, a + i * dx);
  return sum * dx;
}
#endif