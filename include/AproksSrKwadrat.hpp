#ifndef APROKSSRKKWADRAT_HPP
#define APROKSSRKKWADRAT_HPP

#include "SimpsonMetFunc.hpp"
#include <cmath>
#include <functional>
#include <vector>

int power = 0;
double powerFunction(double x) { return std::pow(x, power); }
int i_for_rhs;
std::function<double(double)> f_global;
double rhsFunction(double x) { return f_global(x) * std::pow(x, i_for_rhs); }

/**
 * @brief Aproksymuje funkcję metodą najmniejszych kwadratów za pomocą
 * wielomianu o zadanym stopniu.
 *
 * @param f Funkcja do aproksymacji.
 * @param degree Stopień wielomianu.
 * @param coeffs Wektor wyjściowy do przechowania współczynników wielomianu.
 * @param A Dolna granica całkowania.
 * @param B Górna granica całkowania.
 * @param N Liczba podziałów dla metody Simpsona.
 */
void aproksSrKwadrat(const std::function<double(double)> &f, int degree,
                     std::vector<double> &coeffs, double A, double B,
                     int N = 1000) {

  coeffs.resize(degree + 1);
  std::vector<std::vector<double>> G(degree + 1,
                                     std::vector<double>(degree + 1));
  std::vector<double> b(degree + 1);

  for (int i = 0; i <= degree; ++i) {
    for (int j = 0; j <= degree; ++j) {
      power = i + j; // Set the power for the function
      G[i][j] = simpson_f(powerFunction, A, B, N);
    }
  }

  for (int i = 0; i <= degree; ++i) {
    i_for_rhs = i;
    f_global = f;
    b[i] = simpson_f(rhsFunction, A, B, N);
  }

  for (int i = 0; i <= degree; ++i) {
    for (int j = i + 1; j <= degree; ++j) {
      double factor = G[j][i] / G[i][i];
      for (int k = i; k <= degree; ++k) {
        G[j][k] -= factor * G[i][k];
      }
      b[j] -= factor * b[i];
    }
  }

  for (int i = degree; i >= 0; --i) {
    coeffs[i] = b[i];
    for (int j = i + 1; j <= degree; ++j) {
      coeffs[i] -= G[i][j] * coeffs[j];
    }
    coeffs[i] /= G[i][i];
  }
}

#endif