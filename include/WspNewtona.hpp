#ifndef WSPNEWTONA_HPP
#define WSPNEWTONA_HPP

#include <vector>

/**
 * @brief Oblicza współczynniki wielomianu interpolacyjnego Newtona
 * na podstawie punktów (x, y).
 *
 * @param x Wektor punktów x.
 * @param y Wektor wartości funkcji w punktach x.
 * @return Wektor współczynników wielomianu Newtona.
 */
std::vector<double> wspolczynniki_newtona(const std::vector<double> &x,
                                          const std::vector<double> &y) {
  int n = x.size();
  std::vector<double> a = y;

  for (int j = 1; j < n; ++j) {
    for (int i = n - 1; i >= j; --i) {
      a[i] = (a[i] - a[i - 1]) / (x[i] - x[i - j]);
    }
  }
  return a;
}

#endif