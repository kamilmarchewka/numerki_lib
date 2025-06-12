#ifndef LAGRANGE_HPP
#define LAGRANGE_HPP

#include <vector>

/**
 * @brief Oblicza wartość wielomianu interpolacyjnego Lagrange’a w zadanym
 * punkcie x.
 *
 * @param x Punkt, w którym ma zostać obliczona wartość wielomianu.
 * @param nodeX Wektor zawierający współrzędne x węzłów interpolacji.
 * @param nodeY Wektor zawierający współrzędne y węzłów interpolacji.
 * @return Wartość wielomianu Lagrange’a w punkcie x.
 */
double lagrange(double x, const std::vector<double> &nodeX,
                const std::vector<double> &nodeY) {
  double result = 0.0;
  int n = nodeX.size();

  for (int i = 0; i < n; ++i) {
    double xi = nodeX[i];
    double yi = nodeY[i];
    double L = 1.0;

    // Calculate L_i(x)
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        double xj = nodeX[j];
        L *= (x - xj) / (xi - xj);
      }
    }
    result += yi * L;
  }

  return result;
}

#endif