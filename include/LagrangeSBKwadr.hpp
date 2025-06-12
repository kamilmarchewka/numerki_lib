#ifndef LAGRANGESBKWADRATOWY_HPP
#define LAGRANGESBKWADRATOWY_HPP

#include "Lagrange.hpp"

/**
 * @brief Oblicza średni błąd kwadratowy interpolacji Lagrange'a dla punktów,
 * które nie są węzłami.
 *
 * @param wezlyX Wektor zawierający współrzędne x węzłów interpolacji.
 * @param wezlyY Wektor zawierający współrzędne y węzłów interpolacji.
 * @param wybraneX Wektor zawierający współrzędne x wybranych punktów do
 * interpolacji.
 * @param wybraneY Wektor zawierający współrzędne y wybranych punktów do
 * interpolacji.
 * @return Średni błąd kwadratowy dla punktów, które nie są węzłami.
 */
double lagrangeSBKwadr(const std::vector<double> &wezlyX,
                       const std::vector<double> &wezlyY,
                       const std::vector<double> &wybraneX,
                       const std::vector<double> &wybraneY) {
  double sumaBladow = 0.0;
  size_t liczbaPunktow = 0;

  // Przechodzimy przez wszystkie dane
  for (size_t i = 0; i < wezlyX.size(); ++i) {
    double x = wezlyX[i];
    double y = wezlyY[i];

    // Sprawdzamy, czy punkt jest węzłem (czy jego x jest w wybranych wezłach)
    bool jestWezlem = false;
    for (size_t j = 0; j < wybraneX.size(); ++j) {
      if (x == wybraneX[j]) {
        jestWezlem = true;
        break;
      }
    }

    // Jeśli punkt nie jest węzłem, obliczamy błąd
    if (!jestWezlem) {
      double yInterpolowane = lagrange(x, wybraneX, wybraneY);
      sumaBladow += pow(y - yInterpolowane, 2);
      liczbaPunktow++;
    }
  }

  // Zwracamy średni błąd kwadratowy
  return sumaBladow / liczbaPunktow;
}

#endif