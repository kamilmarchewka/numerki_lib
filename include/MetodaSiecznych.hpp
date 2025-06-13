#ifndef METODASIECZNYCH_HPP
#define METODASIECZNYCH_HPP

#include <cmath>

#ifndef EPSILON
#define EPSILON 1e-15
#endif
#ifndef MAX_ITER
#define MAX_ITER 100
#endif

/**
 * @brief Rozwiązuje równanie nieliniowe metodą siecznych.
 *
 * @param f Funkcja, której pierwiastek ma zostać znaleziony.
 * @param x0 Pierwszy punkt startowy dla metody siecznych.
 * @param x1 Drugi punkt startowy dla metody siecznych.
 * @return Pierwiastek funkcji lub NAN, jeśli warunki nie są spełnione.
 */
double metodaSiecznych(double (*f)(double), double x0, double x1) {
  double fx0 = f(x0), fx1 = f(x1);
  if (isnan(fx0) || isnan(fx1))
    return NAN;
  for (int i = 0; i < MAX_ITER; i++) {
    if (fabs(fx1 - fx0) < EPSILON)
      return NAN;
    double x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
    double fx2 = f(x2);
    if (isnan(fx2))
      return NAN;
    if (fabs(fx2) < EPSILON && fabs(x2 - x1) < EPSILON)
      return x2;
    x0 = x1;
    fx0 = fx1;
    x1 = x2;
    fx1 = fx2;
  }
  return NAN;
}

#endif