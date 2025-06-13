#ifndef METODANEWTONA_HPP
#define METODANEWTONA_HPP

#include <cmath>

#ifndef EPSILON
#define EPSILON 1e-15
#endif
#ifndef MAX_ITER
#define MAX_ITER 100
#endif
/**
 * @brief Rozwiązuje równanie nieliniowe metodą Newtona.
 *
 * @param f Funkcja, której pierwiastek ma zostać znaleziony.
 * @param df Pochodna funkcji f.
 * @param x0 Punkt startowy dla metody Newtona.
 * @return Pierwiastek funkcji lub NAN, jeśli warunki nie są spełnione.
 */
double metodaNewtona(double (*f)(double), double (*df)(double), double x0) {
  for (int i = 0; i < MAX_ITER; i++) {
    double fx = f(x0);
    double dfx = df(x0);
    if (isnan(fx) || isnan(dfx) || fabs(dfx) < EPSILON)
      return NAN;
    double x1 = x0 - fx / dfx;
    if (fabs(x1 - x0) < EPSILON)
      return x1;
    x0 = x1;
  }
  return NAN;
}

#endif