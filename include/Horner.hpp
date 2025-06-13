#ifndef HORNER_HPP
#define HORNER_HPP

#include <vector>

/**
 * @brief Oblicza wartość wielomianu za pomocą schematu Hornera.
 *
 * @param a Wektor współczynników wielomianu, gdzie a[i] to współczynnik przy
 * x^i.
 * @param x Punkt, w którym ma zostać obliczona wartość wielomianu.
 * @return Wartość wielomianu w punkcie x.
 */
double horner(const std::vector<double> &a, double x) {
  double result = a[0];
  for (size_t i = 1; i < a.size(); ++i)
    result = result * x + a[i];
  return result;
}

#endif