#ifndef WIELOMIANNAT_HPP
#define WIELOMIANNAT_HPP

#include <cmath>
#include <vector>

/**
 * @brief Oblicza wartość wielomianu naturalnego w punkcie x
 *
 * @param a Współczynniki wielomianu, gdzie a[i] to współczynnik przy x^i
 * @param x Punkt, w którym obliczamy wartość wielomianu
 * @return Wartość wielomianu w punkcie x
 */
double wielomian_naturalny(const std::vector<double> &a, double x) {
  double result = 0.0;
  for (size_t i = 0; i < a.size(); ++i)
    result += a[i] * pow(x, i);
  return result;
}

#endif