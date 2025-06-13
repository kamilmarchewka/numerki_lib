#ifndef WARTOSCNEWTONA_HPP
#define WARTOSCNEWTONA_HPP

#include <vector>

/**
 * @brief Oblicza wartość wielomianu interpolacyjnego Newtona w punkcie xp
 * na podstawie współczynników a i punktów x.
 *
 * @param x Wektor punktów x, w których obliczono współczynniki.
 * @param a Wektor współczynników wielomianu Newtona.
 * @param xp Punkt, w którym obliczamy wartość wielomianu.
 * @return Wartość wielomianu Newtona w punkcie xp.
 */
double wartosc_newtona(const std::vector<double> &x,
                       const std::vector<double> &a, double xp) {
  double result = a.back();
  for (int i = a.size() - 2; i >= 0; --i) {
    result = result * (xp - x[i]) + a[i];
  }
  return result;
}

#endif